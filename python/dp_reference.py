from typing import List

def dp_trade(prices: List[float], K: int) -> float:
    """
    Computes maximum achievable profit with at most K trades.
    
    prices: list of daily prices
    K: maximum number of buy/sell pairs
    """
    n = len(prices)

    

