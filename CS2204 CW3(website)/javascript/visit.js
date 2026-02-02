function required() {
    var dateValue = document.querySelector('#date').value;
    var timeValue = document.querySelector('#time').value;
    var visitorsValue = document.querySelector('#visitors').value;
    var msg = ['', 'Data not completed; please re-enter', 'Please enter a valid number of people!'];
    var x = document.querySelector('fieldset');
    x.querySelector('p').innerHTML = msg[0];
    if (dateValue === '' || timeValue === '' || visitorsValue === '') {
        x.querySelector('p').innerHTML = msg[1];
    } else if (visitorsValue <= 0 || !Number.isInteger(parseFloat(visitorsValue))) {
        x.querySelector('p').innerHTML = msg[2];
    } else {
        if (reserve(dateValue, timeValue, visitorsValue) === true) {
                    alert('Your reservation is successful!');
        } else {
            alert('Sorry, the reservation is full!')
        }
    }
    return false;
}
function reset() {
    document.getElementById('form1').reset();
}

