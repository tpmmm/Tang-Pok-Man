import java.util.ArrayList;

public class CmdApplyLeave extends RecordedCommand {
    private Employee e;
    private String employeeName;
    private Day startDay;
    private Day endDay;
    private String sDay;
    private String eDay;
    private String leaveType;
    private LeaveRecord record;
    private int leaveDays;
    private int numOfTeamHeads;
    private ArrayList<String> actingTeamNames;
    private ArrayList<String> actingHeadNames;

    @Override
    public void execute(String[] cmdParts) {
        try {
            Company company = Company.getInstance();
            employeeName = cmdParts[1];
            e = company.findEmployee(employeeName);
            sDay = cmdParts[3];
            startDay = new Day(sDay);
            eDay = cmdParts[4];
            endDay = new Day(eDay);
            leaveType = cmdParts[2];
            leaveDays = startDay.daysDifference(endDay);

            SystemDate systemDate = SystemDate.getInstance();  
            systemDate.checkValidStartDate(startDay);

            for (Team t : company.getAllTeams()) {
                String overlap = t.getActingHeadOverlap(e, startDay, endDay);
                if (overlap != null) {
                    System.out.println("Cannot take leave.  " + e.getName() + " is the acting head of " + t.getName() + " during " + overlap + "!");
                    return;
                }
            }

            if (leaveType.equals("AL") || leaveType.equals("BL") || leaveType.equals("SL")) {
                e.checkBalanceOfLeaves(leaveType, startDay.daysDifference(endDay));
            }

            e.checkOverlappingLeave(startDay, endDay); 

            if (leaveType.equals("AL")) {
                e.checkValidForAL(leaveDays);
                e.checkDaysForAL(leaveDays);
                record = new LeaveRecord_AL(startDay, endDay, leaveType);
                e.deductAL(leaveDays);
            }
            else if (leaveType.equals("BL")) {
                e.checkDaysForBL(leaveDays);
                record = new LeaveRecord_BL(startDay, endDay, leaveType);
                e.deductAL(startDay.daysDifference(endDay));
                e.markTakenBL();
            }
            else if (leaveType.equals("NL")) {
                record = new LeaveRecord_NL(startDay, endDay, leaveType);
            }
            else if (leaveType.equals("SL")) {
                record = new LeaveRecord_SL(startDay, endDay, leaveType);
                e.deductSL(leaveDays);
            }
            numOfTeamHeads = e.checkNumOfTeamHeads();
            actingTeamNames = new ArrayList<>();
            actingHeadNames = new ArrayList<>();
            ArrayList<Team> validatedTeams = new ArrayList<>();
            ArrayList<Employee> validatedActingHeads = new ArrayList<>();
            
            ArrayList<Team> expectedTeams = new ArrayList<>();
            for (int i = 0; i < numOfTeamHeads; i++) {
                expectedTeams.add(e.getTeamHeadAt(i));
            }
            
            ArrayList<String> providedTeams = new ArrayList<>();
            for (int i = 5; i < cmdParts.length; i += 2) {
                providedTeams.add(cmdParts[i]);
            }
            
            for (Team expectedTeam : expectedTeams) {
                int cmdIndex = -1;
                for (int i = 0; i < providedTeams.size(); i++) {
                    if (providedTeams.get(i).equals(expectedTeam.getName())) {
                        cmdIndex = 5 + i*2;
                        break;
                    }
                }
                if (cmdIndex == -1) {
                    throw new ExInsufficientArgumentsForActingHead(expectedTeam.getName());
                }
                if (cmdIndex + 1 >= cmdParts.length) {
                    throw new ExInsufficientArgumentsForActingHead(expectedTeam.getName());
                }
                
                String actingHeadNameFromCmd = cmdParts[cmdIndex + 1];
                Team teamObj = company.findTeam(expectedTeam.getName());
                Employee actingHead;
                try {
                    actingHead = company.findEmployee(actingHeadNameFromCmd);
                } catch (ExEmployeeNotFound e) {
                    throw new ExEmployeeNotInThisTeam(new Employee(actingHeadNameFromCmd, 0), teamObj);
                }
                if (!teamObj.hasMember(actingHead)) {
                    throw new ExEmployeeNotInThisTeam(actingHead, teamObj);
                }
                try {
                    actingHead.checkAlreadyApplyLeave(startDay, endDay);
                } catch (ExLeaveOverlapped e) {
                    throw new ExAssigningOnLeaveEmployee(actingHead, e.getOverlappedLeave());
                }
                validatedTeams.add(teamObj);
                validatedActingHeads.add(actingHead);
            }
            
            for (int i = 0; i < validatedTeams.size(); i++) {
                Team t = validatedTeams.get(i);
                Employee a = validatedActingHeads.get(i);
                t.addActingHead(a, startDay, endDay);
                actingTeamNames.add(t.getName());
                actingHeadNames.add(a.getName());
            }
            
            e.addLeaveRecord(record);
            addUndoCommand(this);
            clearRedoList();
            
            System.out.println("Done.");
        } catch (ExEmployeeNotFound e) {
            System.out.println(e.getMessage());
		} catch (ExLeaveOverlapped e) {
            System.out.println(e.getMessage());
        } catch (ExInvalidDate e) {
            System.out.println(e.getMessage());
        } catch (ExInvalidDaysForAL e) {
            System.out.println(e.getMessage());
        } catch (ExInvalidDaysForBL e) {
            System.out.println(e.getMessage());
        } catch (ExNotTakeBLYet e) {
            System.out.println(e.getMessage());
        } catch (ExEmployeeNotInThisTeam e) {
            System.out.println(e.getMessage());
        } catch (ExAssigningOnLeaveEmployee e) {
            System.out.println(e.getMessage());
        } catch (ExInsufficientBalanceOfLeave e) {
            System.out.println(e.getMessage());
        } catch (ExInsufficientBalanceOfSL e) {
            System.out.println(e.getMessage());
        } catch (ExTeamNotFound e) {
            System.out.println(e.getMessage());
        } catch (ExInsufficientArgumentsForActingHead e) {
            System.out.println(e.getMessage());
        }
        
    }

    @Override
    public void undoMe() {
        e.removeLeaveRecord(record);
        if (leaveType.equals("AL")) {
            e.AddAL(startDay.daysDifference(endDay));
        } else if (leaveType.equals("BL")) {
            e.AddAL(startDay.daysDifference(endDay));
            boolean hasBL = false;
            for (LeaveRecord r : e.getRecords()) {
                if (r.getType().equals("BL")) {
                    hasBL = true;
                    break;
                }
            }
            if (!hasBL) {
                e.resetTakenBL();
            }
        } else if (leaveType.equals("SL")) {
                e.AddSL(startDay.daysDifference(endDay));
        }
        try {
            Company company = Company.getInstance();
            for (int i = 0; i < actingTeamNames.size(); i++) {
                Team t = company.findTeam(actingTeamNames.get(i));
                Employee a = company.findEmployee(actingHeadNames.get(i));
                t.removeActingHead(a, startDay, endDay);
            }
        } catch (ExEmployeeNotFound e) {
			System.out.println(e.getMessage());
		} catch (ExTeamNotFound e) {
            System.out.println(e.getMessage());
        }
        addRedoCommand(this);
    }

    @Override
    public void redoMe() {
        try {
            Company company = Company.getInstance();
            e = company.findEmployee(employeeName);
            startDay = new Day(sDay);
            endDay = new Day(eDay);
            leaveDays = startDay.daysDifference(endDay);
            
            SystemDate systemDate = SystemDate.getInstance();  
            systemDate.checkValidStartDate(startDay);

            if (leaveType.equals("AL") || leaveType.equals("BL") || leaveType.equals("SL")) {
                e.checkBalanceOfLeaves(leaveType, startDay.daysDifference(endDay));
            }

            e.checkOverlappingLeave(startDay, endDay); 

            if (leaveType.equals("AL")) {
                e.checkValidForAL(leaveDays);
                e.checkDaysForAL(leaveDays);
                record = new LeaveRecord_AL(startDay, endDay, leaveType);
                e.deductAL(leaveDays);
            }
            else if (leaveType.equals("BL")) {
                e.checkDaysForBL(leaveDays);
                record = new LeaveRecord_BL(startDay, endDay, leaveType);
                e.deductAL(startDay.daysDifference(endDay));
                e.markTakenBL();
            }
            else if (leaveType.equals("NL")) {
                record = new LeaveRecord_NL(startDay, endDay, leaveType);
            }
            else if (leaveType.equals("SL")) {
                record = new LeaveRecord_SL(startDay, endDay, leaveType);
                e.deductSL(leaveDays);
            }
            e.addLeaveRecord(record);

            for (int i = 0; i < actingTeamNames.size(); i++) {
                Team t = company.findTeam(actingTeamNames.get(i));
                Employee a = company.findEmployee(actingHeadNames.get(i));
                t.addActingHead(a, startDay, endDay);
            }

            addUndoCommand(this);
        } catch (ExEmployeeNotFound e) {
			System.out.println(e.getMessage());
		} catch (ExLeaveOverlapped e) {
            System.out.println(e.getMessage());
        } catch (ExInvalidDate e) {
            System.out.println(e.getMessage());
        } catch (ExInvalidDaysForAL e) {
            System.out.println(e.getMessage());
        } catch (ExInvalidDaysForBL e) {
            System.out.println(e.getMessage());
        } catch (ExNotTakeBLYet e) {
            System.out.println(e.getMessage());
        } catch (ExInsufficientBalanceOfLeave e) {
            System.out.println(e.getMessage());
        } catch (ExInsufficientBalanceOfSL e) {
            System.out.println(e.getMessage());
        } catch (ExTeamNotFound e) {
            System.out.println(e.getMessage());
        }
    }
}
