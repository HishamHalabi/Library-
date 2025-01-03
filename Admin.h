class Admin  : public Person  {
public :
    Admin () {

    }
    Admin (string name  , int id) :Person(name, id) {

    }

    void display() {
        cout<<"Admin NAme  :  "<< name <<" Admin ID :   "<<id <<"\n";
    }

     friend ostream& operator<< (ostream &os  , Admin& A)  {
        os<<"Admin NAme  :  "<<  A.name <<" Admin ID :   "<<A.id <<"\n";
        return os;
    }


    void add_book( unordered_map < int ,int,  custom_hash> &av ,
                   unordered_map < int , Book ,  custom_hash> &mp  ,
                   unordered_map < int  , multiset < int > , custom_hash >  &tag_Book,
                   unordered_map < int  , multiset < int > , custom_hash > & cat_Book ,
                   Book &b

    )
    {
        int id =  b.getID() ;
        string cat  = b.getCat() ;
        av[id] =  1;
        mp[id] =  b;
        cat_Book[get_hash(cat)].insert(id)  ;
        unordered_set<string> s  =  b.getTags();

        for (auto &tg:  s)
            tag_Book[get_hash(tg)].insert(id) ;

    }

    void del_book( unordered_map < int , int ,  custom_hash> &av ,
                   unordered_map < int , Book ,  custom_hash> &mp  ,
                   unordered_map < int  , multiset < int > , custom_hash > & tag_Book ,
                   unordered_map < int  , multiset < int > , custom_hash > & cat_Book  ,
                   Book &b

    )
    {
        int id =  b.getID() ;
        string cat  = b.getCat() ;
        av[id] =  0;
        if (cat_Book[get_hash(cat)].count(id))
                 cat_Book[get_hash(cat)].erase(cat_Book[get_hash(cat)].find(id))  ;
        unordered_set<string> s  =  b.getTags();

        for (const string &tg:  s)
             if (tag_Book[get_hash(tg)].count(id))
                     tag_Book[get_hash(tg)].erase(tag_Book[get_hash(tg)].find(id));

    }

};

