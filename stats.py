class StatisticsCalculator:
    def __init__(self, data):
        self.data = data

    def mean(self):
        return sum(self.data) / len(self.data)

    def median(self):
        s = sorted(self.data)
        n = len(s)
        mid = n // 2
        if n % 2:
            return s[mid]
        return (s[mid-1] + s[mid]) / 2

    def mode(self):
        freq = {}
        for x in self.data:
            freq[x] = freq.get(x, 0) + 1
        max_count = max(freq.values())
        return [k for k, v in freq.items() if v == max_count]

if __name__ == "__main__":
    data = [1, 2, 2, 3, 4]
    calc = StatisticsCalculator(data)
    print(f"Mean:   {calc.mean():.2f}")
    print(f"Median: {calc.median():.2f}")
    print(f"Mode:   {' '.join(map(str, calc.mode()))}")
