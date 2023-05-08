def job_sequencing_deadlines(profits, deadlines):
    n = len(profits)
    jobs = sorted(range(n), key=lambda i: -profits[i])
    schedule = [None] * max(deadlines)
    total_profit = 0

    for i in jobs:
        d = deadlines[i] - 1
        while d >= 0 and schedule[d] is not None:
            d -= 1
        if d >= 0:
            schedule[d] = i
            total_profit += profits[i]

    return total_profit
profits = [3, 5, 20, 18, 1, 6, 30]
deadlines = [1, 3, 4, 3, 2, 1, 2]
print(job_sequencing_deadlines(profits, deadlines,))
