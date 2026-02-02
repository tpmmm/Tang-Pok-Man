public class Member 
{
	private String name;
    private Role role;
    public Member(String aName, Role aState) {
        name = aName;
        role = aState;
    }
    public String getName() {
        return name;
    }
	public Role getRole() {
        return role;
    }
    public String getNameAndRole() {
        return role.getNameAndRole(this);
    }
	
    public void setRole(Role r) {
        this.role = r;
    }
}