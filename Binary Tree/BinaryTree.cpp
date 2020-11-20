#include <iostream>
using namespace std;

//jean yves youssef

struct Noeud {
    int val;
    Noeud* fg;
    Noeud* fd;
};

typedef Noeud* Arbre;

Arbre add(int x, Arbre a) { // Appelée dans la syntaxe: nouvel arbre = add(x,ancien arbre)
    if (a == 0) {
        Arbre tmp = new Noeud;
        tmp->val = x;
        tmp->fg = 0;
        tmp->fd = 0;
        return tmp;
    }
    else {
        if (x < a->val) {
            a->fg = add(x, a->fg);
        }
        else {
            a->fd = add(x, a->fd);
        }
        return a;
    }
}

Arbre findEmpty(Arbre tmp){
	if(tmp->fg==0) return tmp;
	else{
		findEmpty(tmp->fg);
	}
}

void removeN(Arbre& tg,Arbre& td){
		if(tg->fd==0) tg->fd=td;	
			else{
				Arbre NFG=findEmpty(td);
				NFG->fg=tg->fd;
				tg->fd=td;
		 	}
}


void remove(int x,Arbre& a,Arbre previous=0){
	if(a==0) return;
	if(x== a->val){
		//check if the value correspond to the root or not
		if(previous!=0){
		
		//this booleam indicate if its from the right or left
		bool indecation;
		(x< previous->val ? indecation=true : indecation=false );
		
		//block of if and else if to handle if the node tp be deleted has at least one empty child
		if(a->fd==0 && a->fg!=0) (indecation ? previous->fg=a->fg : previous->fd=a->fg);
		else if(a->fd!=0 && a->fg==0)(indecation ? previous->fg=a->fd : previous->fd=a->fd );
		else if(a->fd==0 && a->fg==0) (indecation ? previous->fg=0 : previous->fd=0 );
		// this block handle if the node has children 
		else{
			Arbre tmp=a->fg;
			Arbre tmpD=a->fd;
			(indecation ? previous->fg=tmp : previous->fd=tmp );
			removeN(tmp,tmpD);
		}
		
	}
	//in this block we handle if the node is the root
	else{
		if(a->fg==0 && a->fd!=0) a=a->fd;
		else if(a->fd==0 && a->fg!=0) a=a->fg;
		else if(a->fg==0 & a->fd==0) a->val=0;
		else{
		Arbre tmp=a->fg;
		Arbre tmpD=a->fd;
		removeN(tmp,tmpD);
		a=tmp;
		}	
	}
	}
	// those are for the search of the node
	else if(x< a->val){
		return remove(x,a->fg,a);
	}
	else{
		return remove(x,a->fd,a);
	}
}

void add1(int x, Arbre& a) { // inserer x dans a, et modifier a s'il le faut... add1(x,arbre)
    if (a == 0) {
        a = new Noeud;
        a->val = x;
        a->fg = 0;
        a->fd = 0;
    }
    else {
        if (x < a->val) {
            add1(x, a->fg);
        }
        else {
            add1(x, a->fd);
        }
    }
}

void AfficheEnordre(Arbre a) {
    if (a == 0) {
        return;
    }
    else {
        AfficheEnordre(a->fg);
        cout << " " << a->val;
        AfficheEnordre(a->fd);
    }
}

bool find(int x, Arbre a) {
    if (a == 0) return false;
    if (x == a->val) return true;
    if (x < a->val) {
        return find(x, a->fg);
    }
    else {
        return find(x, a->fd);
    }
}





void findInRange(int a,Arbre x, int y){
	for (int i=a;i<=y;++i){
		if(find(i,x)) {
		cout << i <<" ";
		}	
	} 
}

int sum(Arbre a) {
    if (a == 0) return 0;
    return a->val + sum(a->fg) + sum(a->fd);
}

void printBT(const std::string& prefix, const Arbre node, bool isLeft)
{
    if( node != 0 )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "|__" );

        // print the value of the node
        std::cout << node->val << std::endl;

        // enter the next tree level - left and right branch
       // cout<<"old"<<endl;
        printBT( prefix + (isLeft ? "|   " : "    "), node->fg, true);
       // cout<<"new"<<endl;
        printBT( prefix + (isLeft ? "|   " : "    "), node->fd, false);
    }
}

void printBT(const Arbre node)
{
    printBT("", node, false);    
}


int main()
{
    Arbre a = 0; // Arbre vide
	
    for (int i = 0;i<10;++i) {
        int x;
        cout << "x=";cin >> x;
        a = add(x, a);
    //    cout<<"t=";cin>>t;
    }
   
    //nouvelle representation de l'arbre binaire --: fg __: fd
    printBT(a);
    cout<<endl<<"whish number do you like to remove: two childs ";
    int x;cin>>x;
    remove(x,a);
    //AfficheEnordre(a);
    cout<<endl<<"whish number do you like to remove: no childs ";cin>>x;
    remove(x,a);
    cout<<endl<<"whish number do you like to remove: root ";cin>>x;
     remove(x,a);
     printBT(a);
     cout<<endl;
    
	
	//findInRange(4,a,10);
    //cout<<endl;

   /* for (int i = 0;i < 10;++i) {
        int x;
        cout << "x=";cin >> x;
        add1(x, a);
        AfficheEnordre(a);
    }*/

    return 0;
}
