import catch

contest = input('contest ID: ')
maximum_ID = int(input('problem counts: '))

for i in range(0, maximum_ID):
    ch = chr(i + 65)
    # print(ch)
    catch.catcher(contest, ch)