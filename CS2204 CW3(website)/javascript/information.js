var info = [
    "Join our company in Technology Zone of Visionary Innovation Hub for unparalleled opportunities in cutting-edge tech development! 15 QUOTAS LEFT!",
    "Become part of the Innovation Zone at Visionary Innovation Hub, where creativity meets research for groundbreaking solutions! 10 QUOTAS LEFT!",
    "Discover the Eco Zone at Visionary Innovation Hub, dedicated to sustainable practices and technologies for a greener future! 12 QUOTAS LEFT!"
];
var x;
var num = Math.floor(Math.random() * 3);
function msg(){
    x = document.getElementById('promotion_information');
    x.querySelector('h3').innerHTML=info[num];
}
setInterval(looping, 3000);
console.log(info.length);
function looping(){
    num = (num + 1) % info.length    
    x.querySelector('h3').innerHTML=info[num];
}
var show = 0;
function video() {
    if (show == 0) {
        document.querySelector('.video1').setAttribute('style', 'display: none;');
        document.querySelector('.video2').setAttribute('style', 'display: block;');
        document.querySelector('.video2').play();
        show = show + 1;
    } else {
        document.querySelector('.video1').setAttribute('style', 'display: block;');
        document.querySelector('.video2').setAttribute('style', 'display: none;');
        document.querySelector('.video1').play();
        show = show - 1;
    }
}
