class SegmentTree:
    """
    Point update, range query sobre cualquier monoide: (func, default)
    deben cumplir func(default, x) == x, y func debe ser asociativa..
    """

    def __init__(self, data, func=min, default=float('inf')):
        self.func = func
        self.default = default
        self.n = len(data)
        self.sz = 1 << (self.n - 1).bit_length()

        self.t = [default] * (2 * self.sz)
        self.t[self.sz:self.sz + self.n] = data
        for i in reversed(range(1, self.sz)):
            self.t[i] = func(self.t[2 * i], self.t[2 * i + 1])

    def __setitem__(self, i, value):
        i += self.sz
        self.t[i] = value
        i >>= 1
        while i:
            self.t[i] = self.func(self.t[2 * i], self.t[2 * i + 1])
            i >>= 1

    def __getitem__(self, i):
        return self.t[i + self.sz]

    def query(self, l, r):  # func(data[l..r)), medio abierto
        func, t = self.func, self.t
        res_l = res_r = self.default

        l += self.sz
        r += self.sz

        while l < r:
            if l & 1:
                res_l = func(res_l, t[l])
                l += 1
            if r & 1:
                r -= 1
                res_r = func(t[r], res_r)
            l >>= 1
            r >>= 1

        return func(res_l, res_r)
