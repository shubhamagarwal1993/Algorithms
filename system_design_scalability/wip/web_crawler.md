# Web crawler



// Design a web crawler, how would you avoid getting into infinite loops ?

// Estimates
  - how much space it will take to store all the URLs - unordered_map<page v, bool visited> pagesVisited
  - Queue<page> pagesQueue
  - use BFS to crawl web.
  	- on visiting a page, check for page in pagesVisited
  		- if not, then add page v to pagesVisited
		- gather all links on that page and add them to pagesQueue


 - How to check if a page is visited (there is no perfect way)
 	- We can check by page contents
 		- What if there is randomly generated content on the page, it is not really different content every time we visit it
 	- We can check by URL
 		- We must recognize URL parameters as they represent different pages
 		- Different URL parameters might have the same contents, or they might not even change the page (like # in urls)

 - Some ways to solve this:
 	- Have an estimation for degree of similarity based on url and contents
 		- if page is sufficiently similar to other pages, we deprioritize crawling its children

 ----   put these links in a map
| DB | ----------------> On each iteration, choose the highest priority page to crawl
 ----
 has links to crawl

 	- Open up page
 	- create signature of the page based on URL and data on the page
 	- Check if any page with this same/similar signature has been crawled recently
 		- if not then crawl page, insert links into map
 		- else insert this page with low priority
 	- set a min priority, only above this a page will be crawled

Points to note:
 - we might not completely crawl the web, but avoid getting in loops
