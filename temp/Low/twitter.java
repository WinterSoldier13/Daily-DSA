public class Twitter {
	
	//Gives order to the tweets
	private static int timeStamp=0;

	// user storage
	private Map<Integer, User> userMap;

	//Tweet Object
	private class Tweet{
		public int id;
		public int time;
		public Tweet next;

		public Tweet(int id){
			this.id = id;
			time = timeStamp++;
			next=null;
		}
	}


	//User object
	public class User{
		public int id;
		
		//Follwed list
		public Set<Integer> followed;
		//Tweet head pointer
		public Tweet tweet_head;

		public User(int id){
			this.id=id;
			followed = new HashSet<>();
			follow(id); // first follow itself
			tweet_head = null;
		}

		public void follow(int id){
			followed.add(id);
		}

		public void unfollow(int id){
			followed.remove(id);
		}


		// everytime user post a new tweet, add it to the head of tweet list.
		public void post(int id){
			Tweet t = new Tweet(id);
			t.next=tweet_head;
			tweet_head=t;
		}
	}




	/** Initialize your data structure here. */
	public Twitter() {
		userMap = new HashMap<Integer, User>();
	}

	/** Compose a new tweet. */
	public void postTweet(int userId, int tweetId) {
		if(!userMap.containsKey(userId)){
			User u = new User(userId);
			userMap.put(userId, u);
		}
		userMap.get(userId).post(tweetId);

	}



	/**
	*Adds all followed tweets to the heap and take top 10 out from that.
	*/
	public List<Integer> getNewsFeed(int userId) {
		List<Integer> res = new LinkedList<>();

		if(!userMap.containsKey(userId))   return res;

		Set<Integer> users = userMap.get(userId).followed;
		PriorityQueue<Tweet> q = new PriorityQueue<Tweet>(users.size(), (a,b)->(b.time-a.time));
		for(int user: users){
			Tweet t = userMap.get(user).tweet_head;
			// very imporant! If we add null to the head we are screwed.
			if(t!=null){
				q.add(t);
			}
		}
		int n=0;
		while(!q.isEmpty() && n<10){
		  Tweet t = q.poll();
		  res.add(t.id);
		  n++;
		  if(t.next!=null)
			q.add(t.next);
		}

		return res;

	}

	/** Follower follows a followee.*/
	public void follow(int followerId, int followeeId) {
		if(!userMap.containsKey(followerId)){
			User u = new User(followerId);
			userMap.put(followerId, u);
		}
		if(!userMap.containsKey(followeeId)){
			User u = new User(followeeId);
			userMap.put(followeeId, u);
		}
		userMap.get(followerId).follow(followeeId);
	}

	/** Follower unfollows a followee.*/
	public void unfollow(int followerId, int followeeId) {
		if(!userMap.containsKey(followerId) || followerId==followeeId)
			return;
		userMap.get(followerId).unfollow(followeeId);
	}
}