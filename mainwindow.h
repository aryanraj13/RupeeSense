#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<vector<int>> edges;
    vector<string> names;
    vector<vector<int>> minimised;
    bool calculated;
public:

    Graph() {
        V = 0;
        names = vector<string> (V, "");
        calculated = false;
    }
    void setSize(int V) {
        this->V = V;
        adj = vector<vector<int>> (V, vector<int> (V, 0));
        edges.clear();
        names.clear();
        calculated = false;
    }

    int getSize() {
        return V;
    }

    void loadConfig() {
        ifstream fp("debts.txt");
        if (!fp) {
            qDebug() << "Canot open file!";
            return;
        }
        adj = vector<vector<int>> (V, vector<int> (V, 0));
        edges.clear();
        string s;
        while (getline(fp, s)) {
            QString qs = QString::fromStdString(s);
            QStringList lst = qs.split(" ");
            addEdge(lst[0].toInt(), lst[1].toInt(), lst[2].toInt());
            if (fp.fail()) {
                break;
            }
        }
        fp.close();
    }

    void save() {
        ofstream fp("debts.txt");
        if (!fp) {
            qDebug() << "Cannot open file!";
            return;
        }
        for (auto it : minimised) {
            fp << it[0] << " " << it[1] << " " << it[2] << endl;
        }
        fp.close();
    }

    void setName(int index, string name) {
        names[index] = name;
    }

    void addEdge(int source, int target, int debt) {
        adj[source][target] = debt;
        edges.push_back({source, target, debt});
        qDebug() << "Edge added at " << source << " " << target << adj[source][target];
        calculated = false;

    }

    bool BfsPathFinder(vector<vector<int>>& res, int source, int target, int* parent) {
        queue<int> q;
        q.push(source);
        unordered_set<int> st;
        parent[source] = -1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < V; v++) {
                if (!st.count(v) && res[u][v] > 0) {
                    parent[v] = u;
                    if (v == target) {
                        return true;
                    }
                    q.push(v);
                    st.insert(v);
                }
            }
        }
        return false;
    }

    int maximumDebt(vector<vector<int>>& res, int source, int target) {
        int* parent = new int[V];
        int maxDebt = 0;
        int u;
        while (BfsPathFinder(res, source, target, parent)) {
            int debt = INT_MAX;
            for (int v = target; v != source; v = parent[v]) {
                u = parent[v];
                debt = min(debt, res[u][v]);
            }
            for (int v = target; v != source; v = parent[v]) {
                u = parent[v];
                res[u][v] -= debt;
                res[v][u] += debt;
            }
            maxDebt += debt;
        }
        return maxDebt;
    }

    bool cycleReductionHelper(vector<vector<int>>& res, int node, int* parent) {
        queue<int> q;
        q.push(node);
        unordered_set<int> st;
        parent[node] = -1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < V; i++) {
                if (!st.count(i) && res[u][i] > 0) {
                    parent[i] = u;
                    if (i == node) {
                        return true;
                    }
                    q.push(i);
                    st.insert(i);
                }
            }
        }
        return false;
    }

    vector<vector<int>> MinimisedResidualGraph() {
        if (calculated) {
            return minimised;
        }
        int* parent = new int[V];
        int u;
        for (int i = 0; i < V; i++) {
            while (cycleReductionHelper(adj, i, parent)) {
                int debt = INT_MAX;
                for (int v = parent[i]; v != i; v = parent[v]) {
                    u = parent[v];
                    debt = min(debt, adj[u][v]);
                }
                debt = min(debt, adj[parent[i]][i]);
                for (int v = parent[i]; v != i; v = parent[v]) {
                    u = parent[v];
                    adj[u][v] -= debt;
                }
                adj[parent[i]][i] -= debt;
            }
        }
        vector<vector<int>> res(adj);
        for (vector<int> edge : edges) {
            int source = edge[0];
            int target = edge[1];
            if (res[source][target] <= 0) {
                continue;
            }
            int maxDebt = maximumDebt(res, source, target);
            if (maxDebt > 0) {
                res[source][target] = maxDebt;
            }
        }
        vector<vector<int>> result;
        for (vector<int> edge : edges) {
            int source = edge[0];
            int target = edge[1];
            if (res[source][target] > 0) {
                result.push_back({source, target, res[source][target]});
            }
            res[target][source] = 0;
        }
        minimised = vector<vector<int>> (result);
        calculated = true;
        return minimised;
    }
};

struct Edge {
    int from;
    int to;
    float dist;
    float cost;

    Edge(int from = 0, int to = 0, float dist = 0, float cost = 0) {
        this->from = from;
        this->to = to;
        this->dist = dist;
        this->cost = cost;
    }
};

struct EdgeDistComp {
    inline bool operator() (const Edge& a, const Edge& b) {
        return (a.dist <= b.dist);
    }
};

struct EdgeCostComp {
    inline bool operator() (const Edge& a, const Edge& b) {
        return (a.cost <= b.cost);
    }
};

class TravelGraph {
private:
    int V;
    vector<vector<float>> adjDist;
    vector<vector<float>> adjCost;
    vector<Edge> edges;

public:

    TravelGraph() {
        this->V = 0;
    }

    void setSize(int s) {
        V = s;
        adjDist = vector<vector<float>> (V, vector<float> (V, 10000));
        adjCost = vector<vector<float>> (V, vector<float> (V, 10000));
        for (int i = 0; i < V; i++) {
            adjDist[i][i] = adjCost[i][i] = 0;
        }
        edges.clear();
    }

    int getSize() {
        return V;
    }

    int addEdge(int from, int to, float distance, float cost) {
        try {
            if (distance <= 0 || cost <= 0) {
                throw invalid_argument("");
            }
            edges.push_back(Edge(from, to, distance, cost));
            adjDist[from][to] = distance;
            adjCost[from][to] = cost;
        }
        catch(invalid_argument iae) {
            return -1;
        }
        return 1;
    }

    void DeleteEdge(int from, int to, int index) {
        if (index > edges.size()) {
            return;
        }
        if (from >= V || from < 0 || to >= V || to < 0) {
            return;
        }
        adjDist[from][to] = 0;
        adjCost[from][to] = 0;
        edges.erase(edges.begin() + index);
    }

    vector<vector<float>> MinCostAllPoints(int choice = 0) {
        vector<vector<float>> result((choice == 1) ? adjDist : adjCost);
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
                }
            }
        }
        return result;
    }

    vector<int> MinimumCostPath(int source, int choice = 0) {
        vector<vector<float>> graph(choice ? adjDist : adjCost);
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> selected(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        key[source] = 0;
        pq.push(make_pair(source, 0));
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (selected[u]) {
                continue;
            }
            selected[u] = true;
            for (int v = 0; v < V; v++) {
                if (!selected[v] && key[v] > graph[u][v]) {
                    key[v] = graph[u][v];
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }
        return parent;
    }
};

struct Item {
    string name;
    float price;

    Item() {
        name = "";
        price = 0.0;
    }

    Item(string name, float price) {
        this->name = name;
        this->price = price;
    }

};

struct ItemComp {
    inline bool operator() (const Item& a, const Item& b) {
        return a.price <= b.price;
    }
};

class MenuCombination {
    int itemCount;
    vector<Item> items;
    vector<vector<pair<string, int>>> combinations;
    bool isSorted;
public:

    MenuCombination() {
        itemCount = 0;
        isSorted = false;
    }

    MenuCombination(int count) {
        itemCount = count;
        items = vector<Item> (itemCount);
        isSorted = false;
    }

    void Clear() {
        items.clear();
        combinations.clear();
        itemCount = 0;
        isSorted = false;
    }

    void combinationCalculator(int index, float budget, float& totalBudget, vector<pair<string, int>>& temp) {
        if (budget < 0) {
            return;
        }
        if (index > itemCount) {
            return;
        }
        if (index == itemCount) {
            if (budget > totalBudget * 0.1) {
                return;
            }
            combinations.push_back(temp);
            return;
        }
        if (!temp.size() || temp.back().first != items[index].name) {
            temp.push_back({items[index].name, 1});
            combinationCalculator(index, budget - items[index].price, totalBudget, temp);
            temp.pop_back();
        } else {
            temp.back().second++;
            combinationCalculator(index, budget - items[index].price, totalBudget, temp);
            temp.back().second--;
        }
        combinationCalculator(index + 1, budget, totalBudget, temp);
    }

    void addItem(string name, float price) {
        Item item(name, price);
        items.push_back(item);
        itemCount++;
        isSorted = false;
    }

    void deleteItem(int index) {
        items.erase(items.begin() + index);
        itemCount--;
    }

    vector<vector<pair<string, int>>> AllCombinations(float budget) {
        try {
            if (budget <= 0) {
                throw invalid_argument("");
            }
            vector<pair<string, int>> temp;
            if (!isSorted) {
                sort(items.begin(), items.end(), ItemComp());
                isSorted = true;
            }
            combinationCalculator(0, budget, budget, temp);
            combinations.pop_back();
            return combinations;
        }
        catch (invalid_argument iae) {
            return {};
        }
    }
};

struct Transaction {
    int id;
    string description;
    string category;
    float price;

    Transaction() {
        id = 1;
        description = "";
        category = "";
        price = 0.0;
    }

    Transaction(int id, string description, string category, float price) {
        this->id = id;
        this->description = description;
        this->category = category;
        this->price = price;
    }
};

class Distribution {
    unordered_map<string, vector<Transaction>> categories;
    unordered_map<string, float> expenseDistribution;
    vector<Transaction> transactions;
    int count;

public:

    Distribution() {
        count = 0;
    }

    Distribution(vector<Transaction>& transactionList) {
        for (Transaction t : transactionList) {
            categories[t.category].push_back(t);
            expenseDistribution[t.category] += t.price;
        }
        transactions = transactionList;
        count = transactions.size();
    }

    void Clear() {
        categories.clear();
        expenseDistribution.clear();
        transactions.clear();
        count = 0;
    }

    void save() {
        ofstream fp("expenses.txt");
        if (!fp) {
            qDebug() << "Cannot open file!";
            return;
        }
        string s = "";
        s += to_string(expenseDistribution["Maintenance"]) + " ";
        s += to_string(expenseDistribution["Groceries"]) + " ";
        s += to_string(expenseDistribution["Bills"]) + " ";
        s += to_string(expenseDistribution["Miscellaneous"]);
        fp << s << endl;
        fp.close();
    }

    void loadConfig() {
        ifstream fp("expenses.txt");
        if (!fp) {
            qDebug() << "Cannot open file!";
            return;
        }
        string s;
        getline(fp, s);
        QString qs = QString::fromStdString(s);
        qDebug() << s << qs;
        QStringList lst = qs.split(" ");
        qDebug() << lst;
        expenseDistribution["Maintenance"] = lst[0].toFloat();
        expenseDistribution["Groceries"] = lst[1].toFloat();
        expenseDistribution["Bills"] = lst[2].toFloat();
        expenseDistribution["Miscellaneous"] = lst[3].toFloat();
        fp.close();
    }

    void addTransaction(string desc, string cat, float price) {
        Transaction t(count, desc, cat, price);
        transactions.push_back(t);
        categories[cat].push_back(t);
        expenseDistribution[cat] += price;
        ++count;
    }

    void deleteTransaction(int id) {
        if (id < 0 || id >= count) {
            return;
        }
        string cat = transactions[id].category;
        float price = transactions[id].price;
        transactions.erase(transactions.begin() + id);
        expenseDistribution[cat] -= price;
        for (int i = 0; i < categories[cat].size(); i++) {
            if (categories[cat][i].id == id) {
                categories[cat].erase(categories[cat].begin() + i);
                break;
            }
        }
        --count;
    }

    unordered_map<string, vector<Transaction>> getCategories() {
        return categories;
    }

    unordered_map<string, float> getDistribution() {
        return expenseDistribution;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_tableWidget_3_itemChanged(QTableWidgetItem *item);

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

private:
    Ui::MainWindow *ui;
    Graph g;
    TravelGraph tg;
    MenuCombination mc;
    Distribution d;
};
#endif // MAINWINDOW_H
