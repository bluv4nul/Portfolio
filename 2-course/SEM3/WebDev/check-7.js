const url = new URL("https://kodaktor.ru/g/1037528?A=55,33,44&B=21,32,43")

let data = url.search.slice(1).split('&')

let 1 = window.location.search

let X = JSON.parse("["+data[0].slice(2)+"]")
let Y = JSON.parse("["+data[1].slice(2)+"]")

// Ср арфиметическое
let meanX = X.reduce((a,b)=>a+b,0)/X.length
let meanY = Y.reduce((a,b)=>a+b,0)/Y.length

// Числитель
let numerator = X.reduce((sum,x,i)=>sum+(x-meanX)*(Y[i]-meanY),0)

// Знаменатель
let sumSqX = X.reduce((sum, x) => sum + Math.pow(x - meanX, 2), 0)
let sumSqY = Y.reduce((sum, y) => sum + Math.pow(y - meanY, 2), 0)
let denominator = Math.sqrt(sumSqX * sumSqY);

// Коэффициент Пирсона
let r = numerator / denominator
r = (Math.floor(n * 1000) / 1000).toString()



