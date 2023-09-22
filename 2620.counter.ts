function createCounter(n: number): () => number {
    let curNumber: number = n;
    return function () {
        let num = curNumber;
        ++curNumber;
        return num;
    }
}
