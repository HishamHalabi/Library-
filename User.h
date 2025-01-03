
class Person  {
protected:
    string  name   ;
     int id ;

public :

    Person(){}

    Person (string ame , int i)  {
        name =  ame ;
        id =  i ;
    }

    string getName ()  {
        return name ;
    }

    int getID () {
        return id ;
    }

    void display()   {
        cout <<"Book NAme  :  "<<name<<"   Book ID :   "<<id <<"\n";
    }

};

class User  : public Person  {
    unordered_map < string  , int >  freq ;           //cnt_tag
    set < pair < int  , string  >    > interests ; // {tag  , cnt_tag}

    deque < Book  >  book_list ;
    unordered_map<int,int , custom_hash> freq_b ;

    int count_not = 0 ;
    const int mxSz  =  100 ;

public :
    User () {

    }
    User (string name  , int id) :Person(name,id){

    }

    set <pair < int , string > > getInterests (){
        return interests  ;
    }

    void display() {
        cout<<"User NAme  :  "<<name <<" USer ID :   "<<id<<"\n";
    }


    void History () {
        for (auto &b :   book_list) {
            cout<<b;
        }
    }


    void read_book(Book& B)  {
        freq_b[B.getID()]++;
        book_list.push_back(B)   ;
        unordered_set <string >  tags   =  B.getTags() ;
        for (auto &tag  : tags ) {
            if (freq[tag]) {
                interests.erase(interests.find({freq[tag] , tag}))  ;
            }
            freq[tag]++ ;
            interests.insert({freq[tag] , tag})  ;
        }

        book_list.push_back(B) ;
        if(book_list.size() > mxSz)  {
            book_list.pop_front()  ;
        }

    }


    void not_intersted_anymore(Book B)  {
        if (!freq_b[B.getID()]) {
                 return  ;
        }
        freq_b[B.getID()]--;

        unordered_set <string >  tags   =  B.getTags() ;
        for (auto &tag   : tags)  {
            if (!freq[tag])
                continue ;
            interests.erase(interests.find({freq[tag] , tag}))  ;
            freq[tag]-- ;
            interests.insert({freq[tag] , tag})  ;

        }
    }
};
