class Node  {

public :
    string name  ;
    int id ;
    Node * lft  =NULL ;
    Node *rght = NULL ;


    Node(){

}
    Node(string name ,  int id) {
              this->name = name , this->id =  id;
    }


    friend bool operator<(const Node nd1, const Node nd2) {
        return nd1.name < nd2.name;
    }
};

class BST  {
public :
    static Node * Root   ;

    BST() {
        Root  = NULL ;
    }


    void Ins(string name  , int id , Node* cur = Root)  {
        if (Root ==  NULL) {
            Root =  new Node(name, id) ;
            return  ;
        }

        if (cur->name == name)  {
            return  ;
        }

        if (name < cur->name)  {
            if(cur->lft == NULL)  {
                cur->lft =  new Node(name , id);
                return   ;
            }
            return void (Ins(name , id ,  cur->lft));
            return   ;
        }


        if(cur->rght == NULL)  {
            cur->rght =  new Node(name ,id ) ;
            return   ;
        }
        return void (Ins(name, id ,  cur->rght));
    }

    vector  <int > ids ;  // ids of sorted lexi Books  btw L , R
    void inorder(string L , string R  , Node *cur =   Root) {
        if (cur == NULL) {
            return ;   // empty
        }

        if (cur->name >R){
            inorder(L , R , cur->lft)  ;
            return ;
        }
        if (cur-> name   < L) {
            inorder(L , R , cur->rght) ;
            return ;
        }

        inorder(L,  R, cur->lft) ;
        ids.push_back(cur->id) ;
        inorder(L , R, cur->rght) ;
    }


    vector < int >  BOOKS_start_with(string str)  {
        if (str.empty())
                return   vector <int > ();
        string L =  str ,  R =str ;
        R[R.size()  - 1]  =  R[R.size()-1] + 1 ;
        ids.clear() ;
        inorder(L , R , Root) ;
        return ids;
    }

    int Find(string st) {
              ids.clear();
              inorder(st ,st);
              if(ids.empty())
                    return -1 ;
              return ids[0] ;
    }



};
