// design personal financial manager
// connect to your bank accounts, analyze your spending habits, make recommendations

Scoping the question:
 - multiple bank accounts, can remove and add them.
 - pull all financial history the bank allows like incoming money like salary,
   outgoing money like every transactions, current money like account balance and investments
 - all transactions will have a category like food, travel, clothing, etc
   Users can override this, but we can consider that later
 - recommendations
   - immediately: notification of a transaction
   - periodically: crossing max budget, like spening % of salary on this category, other suggestions

Assumptions:
 - adding or removing bank accounts is unusual
 - write heavy system, little access over the week
 - email will be the main source of interaction
 - once a transaction is assigned to a category, it will not change until the user assigns it.
   This is because if the rules change some day, it will change previous data which will confuse user
 - We will be pulling data from the bank, the bank will not push it to us
 - 

Basic Components:
 - pull data depending on user activity, more frequent users can have it pulled every hour, others daily
   - store this raw transaction data into a inmemory db
 - 
// lot of transactions coming in every second

- 
- 