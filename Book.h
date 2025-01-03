class Book  {
    int id ;
    int year ;
    string name  ;
    string path  ;
    string cat ;
    unordered_set<string> tags;


public   :

    Book() {
    }

    Book(string name , int id , int year , string cat){
        this->name  =  name ;
        this->id    =  id ;
        this->year =  year;
        this->cat = cat  ;
    }

    string getName ()  {
        return name ;
    }


    string getCat ()  {
        return cat ;
    }

    int  getID  (){
        return id ;
    }

    int getYear()  {
        return year ;
    }

    unordered_set<string > getTags () {
        return tags   ;
    }

    void display_content() {
        // open file and read from it
    }

    void add_tags(string tg) {
           tags.insert(tg) ;
    }

    friend ostream& operator<< (ostream &os  , Book& B)  {
        os<<"Book NAme  : "  << B.name<<" Book ID :   "<<B.id <<"\n";
        return  os ;
    }

};
