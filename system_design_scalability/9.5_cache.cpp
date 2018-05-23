// web server for simplified search engine
    // This system has 100 machines to respond to search queries
	    // These machines may then call out using processSearch(string query) to another cluster
	    // of machines to actually get the result
    // Machine that responds to a query is chosen at random, so you cannot guarentee that the same machine
	// will always respond to the same request

  // processSearch(string query) is very expensive.
// Design caching mechanism to cache the results of the most recent queries. Explain how you would
// update the cache when data changes

//	Assumptions:
//	 - All query processing happens on the initial machine that was called
//	 - Calling between machines is quick
//	 - The result for a given query is a list of URLS (50 character title and 200 character summary)
//	 - The number of queries to cache is large (millions)
//	 - The most popular queries are extremely popular
//
//	Design for a single system
//	 - Good caching needs to support 2 primary functions:
//	   - expiration of old data so it can be replaced with new data (linked list)
//	   	 - move new items to front of the list. A node is moved to the front every time it is accessed
//	   	 - Thus, end of the list has the stalest information
//	   	 - keep size variable, use it to remove the last element of the linked list when the list exceend it
//	   - effective lookup of keys (hash table)
//	     - maps from a query to the corresponding node in the linked list
//
//  Other things to think about
//	 - handle updating or clearing the cache when the results for a query change


// Caching on a single machine
#include <list>

class QueryResult {
	private:
		string arr[];
	public:
		QueryResult() {}
		~QueryResult() {}
}

class CacheList {
	private:
		std::list<QueryResult> cacheList;
	public:
		CacheList() {}
		~CacheList() {}
		void moveToFront() {}
		void removeFromLinkedList() {}
}

class CacheMap {
	private:
		unordered_map<string, Node*> cacheMap;
	public:
		CacheMap() {}
		~CacheMap() {}
}

class Cache {
	private:
		int cache_size;
		CacheMap cachemap;
		CacheList cacheList;

		QueryResult updateCache(string query) {
			
		}

	public:
		Cache() {
			this.cacheMap = new unordered_map<string, Node*>();
			this.cacheList = new list<QueryResult>();
			this.cache_size = 10;
		}
		~Cache() {}

		QueryResult getResults(string query) {
			if(cacheMap[query]) {

				return cacheMap[query];
			}

			// cache the result
			QueryResult queryResult = Cache::updateCache(query);
		}


		void insertResults(string query, string[] results) {
			if(cacheMap[query]) {
				Node node = cacheMap[query]
				return;
			}
		}
}

// Caching on multiple machines
 - Queries can be sent to any machine randomly
 - Deciding how cache is shared between machines
   - Each machine has its own cache: This will be quick as no machine calls, but lot of cache miss
   - Each machine has copy of cache: This will be slow as update cache will fire N-1 to all other machines
   	 Cache size will be limited by memory of single machine
   - Each machine stores a segment of the cache: machine i will call machine j depening on hash(query)%N
     If no result, then processSearch() and send update cache to machine j

// Cache update
 - some queries are very popular and will never get deleted from cache. Overall, how to update a query
   result in cache when the result changes
   - The contents of a URL changes (page deleted, order change due to page ranking, update in page content)
   - New pages appear for a query

- machine can store the cache in j and in inself as well
- instead of hash%, forwars to a subsection of machines which searches amongst itself
- queries can be assigned to a cluster depending on hash value instead of any random machine
- adding automatic timeouts no matter how many times a query is hit