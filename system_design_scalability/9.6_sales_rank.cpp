// List best-selling products, overall and by category
// E.g. a product is #1056 best-selling product overall, but #13 in sports equipment, and #24 in safety


Question to ask:
 - what sales rank means, is it total sales overtime, sales last month, last week ?

Assumptions:
 - Assume sales over the last week
 - Each product in multiple categories
 - Stats do not need to be 100% up to date

Major Components:
					 -----------------   orders added to DB      ----
					| Purchase System | ----------------------> | DB |
					 -----------------                           ----
	 ---------- 					 -----------------			   |
	| Frontend | <----------------- | Sales rank data | <-----------
	 ----------		 				 -----------------

 - store order into DB
 - every hour we pull sales data from db by category, compute total sales, sort it,
   and store it in cache (in memory).
 - Frontend pulls sales rank from this table/cache rather than hitting the DB and doing its own analytics

Key Issues:
 - analytics are expensive
 - a query every hour to the main DB means querying through all sales for all time

Alternate soln:
 - Get total sales for last week and make a local DB on the sales cluster
 		|--------------------------------------------------------------|	|-----------------------|
 		| Prod ID | Total | Sun | Mon | Tues | Wed | Thurs | Fri | Sat |	| Prod ID | Category ID |
 		|--------------------------------------------------------------|	|-----------------------|
 		|		  |		  |		|	  |		 |	   |	   |	 |	   |	|		  |				|
 		|--------------------------------------------------------------|	|-----------------------|

 - clear the day a week ago (which will be the day today)
 - on every sale, update the total count and count for that product for that day
 - To get total, we can query the table
 - To get sales rank per category, we can join these tables