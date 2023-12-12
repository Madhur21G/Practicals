#include<bits/stdc++.h>
using namespace std;

class eastside;

class marksndancer{ // dealing in apparel
    private:
        float brand_value;
        float avg_prod_cost;
        int kids_prod;
        int men_prod;
        int women_prod;
        friend void merger(marksndancer,eastside);
        friend void new_store(marksndancer, eastside);
        friend void transfer_prod(marksndancer, eastside);
    public:
        marksndancer(int kids_prod, int men_prod, int women_prod, float avg_prod_cost, float brand_value){
            cout << "Enter the brand value";
            cin >> brand_value;
            cout << "Enter the number of kids product";
            cin >> kids_prod;
            cout << "Enter the number of prodcuts for men";
            cin >> men_prod;
            cout << "Enter the number of products for women";
            cin >> women_prod;
        }
};

class eastside{ // dealing in home decoration furnishing
    private:
        float brand_value;
        float avg_prod_cost;
        int kids_fur;
        int house_fur;
        friend void merger(marksndancer, eastside);
        friend void new_store(marksndancer, eastside);
        friend void transfer_prod(marksndancer, eastside);
        // friend void eastside::transfer(marksndancer mnd, eastside est);
    public:
        eastside(float brand_value, float avg_prod_cost, int kids_fur, int house_fur) : brand_value(brand_value), avg_prod_cost(avg_prod_cost), kids_fur(kids_fur), house_fur(house_fur){}
};

void merger(marksndancer mnd, eastside est){
    int value1 = mnd.brand_value;
    int value2 = est.brand_value;
    int total_brand_value = value1 + value2;
    cout << "Total Brand Value : " << total_brand_value << "\n";
    cout << "Do you want to open a new store" << "\n";
    string ans;
    cin >> ans;
    if(ans == "YES"){
        cout << "New Store Opened";
    }
    cout << "Do you want to transfer furniture from Eastside to Marksndancer" << "\n";
    string ans;
    cin >> ans;
    if(ans == "YES"){
        cout << "Transfer furniture from Easiside to Marksndancer";
    }
    cout << "Do you wanr to tranfer apparels from Marksndancer to Eastside" << "\n";
    string ans;
    cin >> ans;
    if(ans == "YES"){
        cout << "Tranfer apparels from Marksndancer to Eastside";
    }
}

void new_store(marksndancer mnd, eastside est){
    cout << "New store to be opened";
    int value = mnd.brand_value + est.brand_value;
    cout << "Total brand value : " << value << "\n";
}

void transfer_prod(marksndancer mnd, eastside est){
    cout << "Enter the number of furnitures to be transferred : " << "\n";
    int n;
    cin >> n;
    int fur_trans = n;
    mnd.kids_prod -= n;
    est.kids_fur += n;
    cout << "Transfer Succesful" << "\n";
}

int main(){



    return 0;
}