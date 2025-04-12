def is_square(n):
    if n < 0:
        return False
    return int(n**0.5)**2 == n

def precompute_squares(limit):
    """Precomputes all square numbers up to a given limit."""
    squares = set()
    i = 1
    while i * i <= limit:
        squares.add(i * i)
        i += 1
    return squares

def main():
    year_one, year_two = map(int, input().split())
    
    year_squares = precompute_squares(year_two)
    month_squares = precompute_squares(12) 
    day_squares = precompute_squares(31)  
    
    square_days = 0
    for year in range(year_one, year_two + 1):
        if year in year_squares:
            for month in range(1, 13):
                if month in month_squares:
                    for day in range(1, 32):
                        if day in day_squares:
                            square_days += 1
    print(square_days)
    
if __name__ == "__main__":
    main()

