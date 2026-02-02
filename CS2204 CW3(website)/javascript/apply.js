
var tech = document.querySelector('.tech');
var techZone = document.getElementById('Technology_Zone')
var inno = document.querySelector('.inno');
var innoZone = document.getElementById('Innovation_Zone')
var eco = document.querySelector('.eco');
var ecoZone = document.getElementById('Ecology_Zone')
var check = 0
window.onload = function() {
    function initial() {
        tech.setAttribute('style', 'background-color: white;')
        inno.setAttribute('style', 'background-color: rgb(210, 172, 243);')
        innoZone.setAttribute('style', 'display: none;')
        eco.setAttribute('style', 'background-color: rgb(210, 172, 243);')
        ecoZone.setAttribute('style', 'display: none;')
    }
    initial();
}
tech.onclick = function() {
    tech.setAttribute('style', 'background-color: white;')
    inno.setAttribute('style', 'background-color: rgb(210, 172, 243);')
    eco.setAttribute('style', 'background-color: rgb(210, 172, 243);')
    techZone.setAttribute('style', 'display: block;')
    innoZone.setAttribute('style', 'display: none;')
    ecoZone.setAttribute('style', 'display: none;')
}
inno.onclick = function() {
    tech.setAttribute('style', 'background-color: rgb(210, 172, 243);')
    inno.setAttribute('style', 'background-color: white;')
    eco.setAttribute('style', 'background-color: rgb(210, 172, 243);')
    techZone.setAttribute('style', 'display: none;')
    innoZone.setAttribute('style', 'display: block;')
    ecoZone.setAttribute('style', 'display: none;')
}
eco.onclick = function() {
    tech.setAttribute('style', 'background-color: rgb(210, 172, 243);')
    inno.setAttribute('style', 'background-color: rgb(210, 172, 243);')
    eco.setAttribute('style', 'background-color: white;')
    techZone.setAttribute('style', 'display: none;')
    innoZone.setAttribute('style', 'display: none;')
    ecoZone.setAttribute('style', 'display: block;')
}
document.querySelector('.c1').setAttribute('style', 'width: 65%;')
document.querySelector('.c2').setAttribute('style', 'width: 35%;')
var buttons = document.querySelectorAll('button');
var x = 0;
for (var i = 0; i < buttons.length; i++) {
    buttons[i].onclick = getRank;
}
function getRank() {
    var table = document.querySelectorAll('tbody tr');
    var button = this;
    var form = button.parentNode;
    var zone = form.parentNode;
    var name = form.querySelector('label').innerText;
    var rank = form.querySelector('input').value;

    zone = zone.id.replace('_', ' ');
    if (!(Number.isInteger(Number(rank)))|| !(Number(rank) %1 === 0) || (rank === '')) {
        alert('Please enter the rank of chosen company');
    } else if (rank < 1 || rank > 10) {
        alert('Please enter the rank of chosen between 1 and 10')
    } else {
        rank = Number(rank);
        cell = table[rank - 1].querySelectorAll('td');
        if(checkDuplicate(name, table)) {
            alert('You have already chosen this company');
        } else if (cell[0].innerText != '') {
            alert('You have already chosen this rank');
        } else {
            check = check + 1;
            cell[0].innerHTML = zone;
            cell[1].innerHTML = name;
            var rankNum = '';
            if (rank === 1){
                rankNum = 'st';
            } else if (rank === 2) {
                rankNum = 'nd';
            } else if (rank === 3) {
                rankNum = 'rd';
            } else {
                rankNum = 'th';
            }
            alert('You have chosen ' + name + ' as your '+ rank + rankNum + ' chosen company in ' + zone + ' successfully')
            updateTable();
        }
    }
}
function checkDuplicate(name, table) { 
    for (var i = 0; i < 10; i++) {
        cell1 = table[i].querySelectorAll('td')
        if (cell1[1].innerText === name) {
            return true;
        }
    }
    return false;
}

function updateTable() {
    x = x + 1;
    const d = new Date();
    document.getElementById("time").innerHTML = d;
    document.getElementById('num').innerHTML = check;
}
var sub = document.getElementById('sub');
sub.onclick = function(table) {
    document.getElementById('subtext').innerHTML = '';
    var hasGap = false;
    var isEmpty = true;
    
    for (var i = 0; i < 10; i++) {
        cell2 = document.querySelectorAll('tbody tr')[i].querySelectorAll('td')
        var q = 0;
        if (i != 0) {
            q = i - 1;
        }
        if(cell2[1].innerText != '' && document.querySelectorAll('tbody tr')[q].querySelectorAll('td')[1].innerText === '') {
            var a = i;
            var rankNum = '';
            if (a === 1){
                rankNum = 'st';
            } else if (a === 2) {
                rankNum = 'nd';
            } else if (a === 3) {
                rankNum = 'rd';
            } else {
                rankNum = 'th';
            }
            hasGap = true;
            break;
        }
    }
    console.log(cell2)
    if (check == 0) {
        document.getElementById('subtext').innerHTML = 'You have not chosen any company.';
    } else if (hasGap) {
        document.getElementById('subtext').innerHTML = 'You have not chosen your ' +a+rankNum+ ' chosen companies, you can not leave any gap between your chosen companies';
    } else {
        document.getElementById('subtext').innerHTML = 'You have successfully submitted your application at time ' + new Date();
    }
} 
var re = document.getElementById('re');
re.onclick = function(name, table) { 
    for (var i = 0; i < 10; i++) {
        cell3 = document.querySelectorAll('tbody tr')[i].querySelectorAll('td');
        cell3[0].innerHTML = ''
        cell3[1].innerHTML = ''
    }
    document.getElementById('time').innerHTML = new Date();
    document.getElementById('num').innerHTML = 0;
    check = 0
}