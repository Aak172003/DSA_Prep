// My Notes

#include <iostream>
#include <queue>
using namespace std;

void interLeave(queue<int> &q)
{
    // half the queue , via using k ,
    // so hum k th iterate krte hue queue ke mid tk jaenge

    int n = q.size();
    int half = n / 2;
    int count = 0;

    // Hum ek q2 queue bnate hai jisme ,
    // hum first half element q se pop krke q2 me daal dnge
    queue<int> q2;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;

        // if count == half , means react at middle point from where partition occurs)
        if (count == half)
            break;
    }

    // step - Interleaving
    // Do interleaving q2 se pop krke q me daalna
    // then q se pop krke q me aage daalna
    // is tarah krke saare emelents from q2 se q me aajaenge
    while (!q2.empty() && !q.empty())
    {
        int first = q2.front();
        q2.pop();
        q.push(first);

        int second = q.front();
        q.pop();
        q.push(second);
    }

    // Check if n is odd means ek top element or hoga , jo q me hoga ,
    // usko q se pop krke q ke last me oush krenege
    if (n & 1)
    {
        int element = q.front();
        q.pop();
        q.push(element);
    }
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);

    interLeave(q);

    cout << "printing Queue after reversing recursively" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
