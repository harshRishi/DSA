#include <string>
using namespace std;

template <typename V>
class mapNode
{
public:
    string key;
    V value;
    mapNode *next;

    // construtor
    mapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    // delete {distrutor}
    ~mapNode() // next information will going to come along 'this' keyword
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    ourmap<V> **buckets;
    int count;
    int numBuckets; // bucket size

public:
    // construtor
    ourmap()
    {
        int count = 0;
        int numBuckets = 5;
        buckets = new mapNode<V> *[numBuckets]; // created a bucket in heap storage which have mapNode<V> type data with template V, and this bucket is of size numBucket
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL; // this array is storing pointing so append nULL to every single block
        }
    }

    // ease the whole Bucket array
    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++) // delete call Linked list in the bucket
        {
            delete buckets[i];
        }
        delete buckets; // thann delete the bucket itself
    }

    int size()
    {
        return count;
    }

private:
    int getBucketIndex(string key) // function that returns a bucketIndex for ourMap's key (which is a string)
    {
        int hashCode = 0;
        int currentCoeff = 1;
        // idea is to make base as multiplayer ie, ab = a*p^1{base is one and p is a prime number} + b*p^0
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets; // conpression function{to make hashCode fit into the bucket array index range}
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets;
        }
        return hashCode % numBuckets;
    }

    void rehash()
    {
        mapNode<V> **temp = buckets;              // made a temp mapNode which will going to store old Buckets array
        buckets = new mapNode<V>[2 * numBuckets]; // made aur old bucket to point a new bucket with size 2 of old buckets

        while (int i = 0; i < 2 * numBuckets; i++) // clear the grabage value in the new bucket
        {
            buckets[i] = NULL;
        }

        int oldNumBucket = numBuckets; // this will store the old bucket size
        numBuckets *= 2;               // made our bucket size twice
        count = 0;                     // we'll increase the count as we insert the new key-value pairs in the new buckets

        for (int i = 0; i < oldNumBucket; i++) // travek the old bucket and fill the new one with it's key value pairs
        {                                      // {CAUTION: copy all elements in the Linked List seperatly in the new BucketIndex so that after hashFunctin we get (in the insert) find the rigth hashCode as it requre the size of the buckets which we have change 2 * numbucket}
            mapNode<V> *head = temp[i];        // pointer pointing towards ith index in the old buckets
            while (head != NULL)               // travel the linked list and copy it to the new one in seprate indexs in the new Buckets
            {
                insert(head->key, head->value); // ******** as our buckets is pointing towards new bockets so insert will insert the pairs in the new one as also increase the count respectively
                head = head->next;
            }
        }

        // delete the old bucket that is temp'
        for (int i = 0; i < oldNumBucket; i++)
        {
            mapNode<V> *head = temp[i];
            delete head; // as this is recusive it will delete all pairs in the linkedList
        }
        delete[] temp; // here we've delete the array itself
    }

public:
    double getLoadFactor()
    {
        return (1.0 * count) / numBuckets;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        mapNode<V> *head = buckets[bucketIndex];

        while (head != NULL)
        {
            if (head->key == key)
                return head->value;
        }
        return 0;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        // create a head that points at bucketIndex;
        mapNode<V> *head = buckets[bucketIndex];
        // check if there is anything already present if yes insert newNode
        while (head != NULL)
        {
            // In case we found that key already exist
            if (head->key == key)
            {
                head->value == value; // just update the value
                return;
            }
            head->next = next;
        }
        // In case we didn't found anyKey or matching key in LL
        // simply create new mapNode and insert it
        mapNode<V> *node = new mapNode<V>(key, value);
        node->next = head;           // connected the newNode with others
        buckets[bucketIndex] = node; // bucket's bucketIndex is now storing address of newNode as head;
        count++;                     // after creating new Node increase count

        //if load Factor is more than 0.7 rehash
        double loadFactor = ((1.0 * count) / numBuckets);
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);   // find the index corresponding to that key
        mapNode<V> *head = buckets[bucketIndex]; // make a pointer that have info about where that bucletIndex is pointing(i,e head of LinkedList)
        mapNode<V> prev = NULL;
        while (head != NULL)
        {
            if (head->key == key) // we found the key
            {
                if (prev == NULL)                      // head itself is key we want to delete
                    buckets[bucketIndex] = head->next; // skipped head
                else                                   // in case (head->key == key)
                    prev->next = head->next;           // skip the ket element

                V val = head->value; // save before delete so that later we can return
                head->next = NULL;   // as our delete function is recusive to to save further element we need to break the chain
                delete head;
                count--; // as we have delete the element
                return val;
            }
            // for futher propagation
            prev->next = head;
            head = head->next;
        }
        return 0;
    }

    V search(string key)
    {
        int bucketIndex = getBucketIndex(key);
        mapNode<V> *head = buckets[bucketIndex];

        while (head != NULL)
        {
            if (head->key = key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
};