//ШАБЛОН - template

var myname = 'Ilya';

//Контактуационная интерполяция строк (устаревший избыточный вариант)
var greeting1 = 'Hello' + myname + '!';

/*
Шаблонные строки
${myname} - плейсхолдер
*/
var greeting2 = `Hello, ${myname}!`;


const colors = {
    rgb: {
        names: ['red', 'green', 'blue'],
        numbers: ['rgb(255,0,0)', 'rgb(0,255,0)', 'rgb(0,0,255)']
    }
}

const { rgb: { numbers: [, , blueNumber] } } = colors;


const myname2 = "Andrew";
const myheigth = 189;

const data = `${myname2} is ${myheigth} cm`

const show = (...x) => [...x];

show`${myname2} is ${myheigth} cm`

//ПАТТЕРН - pattern, pattern.html

//МАСТЭШ

