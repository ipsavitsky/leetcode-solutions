type Fn = (...params: number[]) => number

function memoize(fn: Fn): Fn {
    let calls = new Map<string, number>()
    return function (...args) {
        const str_args = JSON.stringify(args)
        if (calls.has(str_args)) {
            return calls.get(str_args)
        }
        let res = fn(...args)
        calls.set(str_args, res)
        return res
    }
}
