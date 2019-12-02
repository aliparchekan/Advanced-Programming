#ifndef api_hpp
#define api_hpp

#include <vector>
#include <string>
using namespace std;

typedef vector<string> List;

enum UserType {Admin, Artist, Editor, Normal};

struct UserData
{
    string firstname;
    string lastname;
    string username;
    UserType userType;
};

class ItemDoesNotExists;
class NotAuthorized;
class MethodNotAvailable;
class InvalidArguments;
class InvalidCredentials;
class AlreadyExists;

class GerdabifyAPI
{
public:
    void enterBrowserMode();
    void goToHome();
    void goToPlayList();
    void goToLibrary();
    void goToAlbum();
    void goToArtist();
    List search(string);
    void select(string);
    List list();
    List listMusics();
    List listAlbums();
    List listPlaylists();
    List listArtists();
    void play();
    void addTo(string);
    void goTo(string);
    void createPlaylist(string);
    void clearPlaylist(string);
    void remove(string);
    void orderItem(string, int);
    void rate(int);
    string getArtist();
    string getAlbum();
    int getLength();
    string getName();
    string getCompleteName();
    int getRate();
    int getUserRate();
    int getCriticRate();
    void enterPlayMode();
    void next();
    void previous();
    void pause();
    void seek(int, int);
    void shuffle();
    void repeatOne();
    void repeat();
    void signup(UserData, string);
    void login(string, string);
    void addMusic(string, string);
    void addAlbum(string, string);
    void validate();
    UserData getUserDetails(string);
    void verifyUser(string);
};

#endif
