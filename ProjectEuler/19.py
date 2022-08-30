days_1st = list()
day_counter = 1
for year in range(1900, 2001):
    for month in range(1,13):
        #Skip for year 1900 as count starts from 1901, but this still 
        #adds the days hence keeping the cycle in sync!
        if year != 1900: 
            days_1st.append(day_counter)
        if month == 4 or month == 6 or month == 9 or month == 11:
            day_counter+=30
        elif month == 2 and ((year % 100 == 0 and year % 400 == 0) or (year % 100 != 0 and year % 4 == 0)):
            day_counter+=29
        elif month == 2:
            day_counter+=28
        else:
            day_counter+=31
# mod 7 because since the day the counting started (1 Jan 1900 - 
# Monday) Every 7th day is a sunday!
days_sunday = list(filter(lambda x: x % 7 == 0, days_1st))
print(len(days_sunday)) 