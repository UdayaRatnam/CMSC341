#include "Media.h"


Media::Media(string title, string artist, string type, int year, int rank ){

    SetTitle(title);
    SetArtist(artist);
    SetType(type);
    SetYear(year);
    SetRank(rank);
};

void Media::SetTitle(string title){
    m_title = title;
}
void Media::SetArtist(string artist){
    m_artist = artist;
}
void Media::SetType(string type){
    m_type = type;
}
void Media::SetYear(int year){
    m_year = year;
}
void Media::SetRank(int rank){
    m_rank = rank;
}
string Media::GetTitle()const{

    return m_title;
}
string Media::GetArtist()const{
    return m_artist;
}
string Media::GetType()const{
    return m_type;
}
int Media::GetYear()const{

    return m_year;
}
int Media::GetRank()const{
    return m_rank;
}

ostream& operator<<(ostream& out, Media& m){
    return out<<m.GetYear();
    return out;
}

bool Media::operator<(const Media& m){

    if(m.GetYear() < m_year){
        return true;
    }
    return false;
}