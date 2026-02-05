function task(x){
    return x == null ? "1155288" : (x == 1 ?  1 : x*task(x-1))
}
     
console.log(task(10)) 