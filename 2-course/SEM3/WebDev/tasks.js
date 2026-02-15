function task(x){
    return new Promise((res, rej) => {
        if (x >= 18){
            rej('No')
        } else if (x === 0) {
            res('1155288')
        } else{
            res("Yes")
        }
    })
}

console.log(task(18))