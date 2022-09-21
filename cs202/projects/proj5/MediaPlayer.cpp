#include "MediaPlayer.h"


//Name: MediaPlayer - Overloaded Constructor
//Precondition: None
//Postcondition: Creates a new MediaPlayer and passes the media filename
MediaPlayer::MediaPlayer(string filename){
    
    LoadCatalog(filename);
    
}
//Name: ~MediaPlayer - Destructor
//Precondition: None
//Postcondition: Creates a new MediaPlayer
MediaPlayer::~MediaPlayer(){

 
    for(unsigned int i = 0; i < m_mediaCatalog.size();i++){
        delete m_mediaCatalog.at(i);
    }
    m_mediaCatalog.clear();
    //m_playList.~Tqueue();
    
    cout<<"Thank you for using UMBC Media Player"<<endl;
}
//Name: LoadCatalog(string filename)
//Precondition: Requires filename
//Postcondition: Loads the file into the m_mediaCatalog (as media)
void MediaPlayer::LoadCatalog(string filename){
    string title, artist, type, temp;
    int year, rank;
    ifstream inputstream;
    inputstream.open(filename);
    while(getline(inputstream, title, ';')){
        getline(inputstream,artist,';');
        getline(inputstream,type,';');
        getline(inputstream,temp,';');
        year = stoi(temp);
        getline(inputstream,temp,'\n');
        rank = stoi(temp);
        Media* temp = new Media(title, artist,type, year, rank);
        m_mediaCatalog.push_back(temp);

    }
    cout<<m_mediaCatalog.size()<<" media files loaded"<<endl;

}
 //Name: MainMenu
//Precondition: None
//Postcondition: Manages the application and the menu
void MediaPlayer::MainMenu(){
    int choice;
    bool notFive = true;
    int action;
    

    do{
        cout<<"What would you like to do?"<<endl;
        cout<<"1. Display Media by Type and Year"<<endl;
        cout<<"2. Add Media to Playlist"<<endl;
        cout<<"3. Display Playlist"<<endl;
        cout<<"4. Sort Playlist by Year"<<endl;
        cout<<"5. Quit"<<endl;
        cin >> choice;
    


        switch(choice){
            case 1:
                action = DisplayMedia();
                if(action == 0){
                    cout<<"No media found with those criteria"<<endl;
                }
                else{
                    cout<<action<<" media found"<<endl;
                }
                break;
            case 2:
                AddMedia();
                break;
            case 3:
                DisplayPlaylist();
                break;
            case 4:
                SortPlaylist();
                break;
            case 5:
                notFive = false;
                break;
            default:
                break;
        }

    }while(notFive);

    
    

}
//Name: DisplayMedia
//Precondition: User enters year (1958-2020)
//              (shows all years even if no media of that type exists for a particular year)
//Postcondition: Lists all media (numbered) for that year and returns int
//               of number found with that criteria
int MediaPlayer::DisplayMedia(){
    int count = 0;
    int year;
    string type;
    do{
        cout<<"Which media type do you want to display?"<<endl;
        cout<<"music"<<endl;
        cout<<"podcast"<<endl;
        cin >> type;

    }while(type.compare("music") != 0 && type.compare("podcast") != 0);
    do{
        cout<<"Which year would you like to display? (1958-2020)"<<endl;
        cin >> year;

    }while(year < 1958 || year > 2020);
    
    cout<<"******"<<year<<"*****"<<endl;
    for(unsigned int i = 0; i < m_mediaCatalog.size(); i++){

        if(m_mediaCatalog.at(i)->GetYear() == year && m_mediaCatalog.at(i)->GetType().compare(type) == 0){
            cout<<i+1<<". "<<m_mediaCatalog.at(i)->GetTitle()<<" by "<<m_mediaCatalog.at(i)->GetArtist()<<endl;
            count++;
        }
    }


    return count;
}
//Name: AddMedia
//Precondition: m_mediaCatalog is populated
//Postcondition: Displays the current list and adds media
//               to the m_playList
void MediaPlayer::AddMedia(){
    DisplayPlaylist();
    int mediaNumber;
    cout<<"Choose the media you would like to add to the playlist."<<endl;
    DisplayMedia();
    
    do{
        cout<<"Enter the number of the media you would like to add"<<endl;
        cin >> mediaNumber;
    }while(mediaNumber < 1 || mediaNumber > 6300);
    m_playList.Enqueue(m_mediaCatalog.at(mediaNumber-1));
    cout<<m_mediaCatalog.at(mediaNumber-1)->GetTitle()<<" by "<<m_mediaCatalog.at(mediaNumber-1)->GetArtist()<<" added to the playlist"<<endl;
    
    


    
    
}
//Name: DisplayPlaylist
//Precondition: None (will indicate if list is empty)
//Postcondition: Displays the playlist
void MediaPlayer::DisplayPlaylist(){
    if(m_playList.Size() == 0){
        cout<<"Playlist is currently empty"<<endl;
    }
    else{

        for(int i = 0; i < m_playList.Size(); i++){

            cout<<i+1<<". "<<m_playList.At(i)->GetTitle()<<" by "<<m_playList.At(i)->GetArtist()<<" from "<<m_playList.At(i)->GetYear()<<endl;
        }
    }
   
}
//Name: SortPlaylist
//Precondition: None (will indicate if list is empty)
//Postcondition: Sorts the playlist by year
void MediaPlayer::SortPlaylist(){

    if(m_playList.IsEmpty()){
        cout<<"Playlist is currently empty"<<endl;
    }
    else{

        int minimum;
        for(int i = 0; i < m_playList.Size()-1; i++){
            minimum = i;
            for(int j = i+1; j < m_playList.Size(); j++){

                if(*m_playList.At(minimum) < *m_playList.At(j)){
                    minimum = j;
                    
                }
            }
            if(i != minimum){
                
                Media* temp = m_playList.At(minimum);
                m_playList.At(minimum) = m_playList.At(i);
                m_playList.At(i) = temp;
                
                
            }
            
        }

        cout<<"Done Sorting by year"<<endl;
        cout<<m_playList.Size()<<" items sorted"<<endl;
       

        
    }
    
}