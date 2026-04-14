import time

def solve_reference(n, r_max, c_max, trades):
    # Reference implementation for performance comparison
    dp = [[0] * (c_max + 1) for _ in range(r_max + 1)]
    for p, r, c in trades:
        for curr_r in range(r_max, r - 1, -1):
            for curr_c in range(c_max, c - 1, -1):
                dp[curr_r][curr_c] = max(dp[curr_r][curr_c], dp[curr_r - r][curr_c - c] + p)
    return dp[r_max][c_max]

if __name__ == "__main__":
    try:
        with open("data/small_instance.txt", "r") as f:
            lines = f.readlines()
            n, r_max, c_max = map(int, lines[0].split())
            trades = [list(map(int, l.split())) for l in lines[1:] if l.strip()]
        
        start = time.time()
        res = solve_reference(n, r_max, c_max, trades)
        print(f"Python Result: {res} | Time: {(time.time()-start)*1000:.2f} ms")
    except Exception as e:
        print(f"File Error: {e}")
