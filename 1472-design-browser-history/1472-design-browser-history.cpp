class Node {
    public:
    string data;
    Node*next;
    Node*back;
    Node() : data("") , next(NULL) , back(NULL){};
    Node(string x) : data(x) , next(NULL) , back(NULL){};
    Node(string x , Node*next , Node* back) : data(x) , next(next) , back(back){};
};



class BrowserHistory {
    private:
    Node* currPage;
public:
    BrowserHistory(string homepage) {
        currPage = new Node(homepage);
        
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        currPage->next = newNode;
        newNode->back = currPage;
        currPage = newNode;

        
    }
    
    string back(int steps) {
        while(steps ){
            if(currPage->back){
                currPage = currPage->back;
                steps--;
            }
            else
            break;
        }
        return currPage->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(currPage->next){
                currPage = currPage->next;
                steps--;
            }
            else
            break;
        }
        return currPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */