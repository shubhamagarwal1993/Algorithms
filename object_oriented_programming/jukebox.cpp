// singleton design pattern
class Jukebox {
	private:
		List<Playlist> playlists;
	public:
		Jukebox() {}
		
};

class Playlist {
	private:
		List<CD> cds;
	public:
		Playlist() {}

		void addSong(Song song) {}
		void deleteSong(Song song) {}
}

class CD {
	private:
		List<Song> song;
	public:
		CD() {}
};

class Song {
	private:
		string Artist;
	public:
		Song() {}
};

class Artist {
	private:
		string name;
	public:
		Artist(string name) {
			this.name = name;
		}	
}