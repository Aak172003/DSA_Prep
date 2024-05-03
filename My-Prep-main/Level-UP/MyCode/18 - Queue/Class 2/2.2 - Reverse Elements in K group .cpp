
//  ******************************* My Notes *********************************************

/*
GFG Link - https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
*/

queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.

    stack<int> st;

    // jb tk k = 0 nhi ho jata tb tk q se element pop krke stack me push krna hai
    while (k--)
    {
        st.push(q.front());
        q.pop();
    }
    // phr queue me -1 daalna hai
    q.push(-1);
    // jb tk stack khali nhi ho jata , q me push krna hai or stack se pop krna hai
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // In queue , jb tk -1 na encounter ho jae ,
    // hume queue me aage se element nikal kr piche lgate rhna hai
    while (q.front() != -1)
    {
        int frontdata = q.front();
        q.pop();
        q.push(frontdata);
    }
    // at Last q se -1 ko pop kr lena hai
    q.pop();
    return q;
}