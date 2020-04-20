// 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

// 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
// 写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

 

// 进阶:

// 你是否可以在 O(1) 时间复杂度内完成这两种操作？

 

// 示例:

// LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // 返回  1
// cache.put(3, 3);    // 该操作会使得密钥 2 作废
// cache.get(2);       // 返回 -1 (未找到)
// cache.put(4, 4);    // 该操作会使得密钥 1 作废
// cache.get(1);       // 返回 -1 (未找到)
// cache.get(3);       // 返回  3
// cache.get(4);       // 返回  4

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strings"
    "strconv"
)

type DoubleListNode struct {
    Prev *DoubleListNode
    Next *DoubleListNode
    Key int
    Val int
}

type DoubleList struct {
    head *DoubleListNode
    tail *DoubleListNode
    size int
}

func (this *DoubleList) AddHead(newNode *DoubleListNode) {
    this.size++
    if this.head == nil {
        this.head = newNode
        this.tail = newNode
        return
    }
    newNode.Next = this.head
    this.head.Prev = newNode
    this.head = newNode
}

func (this *DoubleList) Remove(node *DoubleListNode) {
    this.size--
    if this.head == node {
        this.head = this.head.Next
    }
    if this.tail == node {
        this.tail = this.tail.Prev
    }
    if node.Prev != nil {
        node.Prev.Next = node.Next
    }
    if node.Next != nil {
        node.Next.Prev = node.Prev
    }
    node.Next = nil
    node.Prev = nil
}

func (this *DoubleList) RemoveTail() *DoubleListNode {
    if this.tail == nil {
        return nil
    }
    this.size--
    if this.tail == this.head {
        ret := this.tail
        this.tail = nil
        this.head = nil
        return ret
    }
    ret := this.tail
    if this.tail.Prev != nil {
        this.tail = this.tail.Prev
        this.tail.Next = nil
    }
    ret.Prev = nil
    ret.Next = nil
    return ret
}

func (this *DoubleList) Size() int {
    return this.size
}

func (this *DoubleList) PrintAll() {
    cur := this.tail
    for cur != nil {
        fmt.Print(cur.Key, " ")
        cur = cur.Prev
    }
    fmt.Println("")
}

// --------------------------------------

type LRUCache struct {
    List *DoubleList
    Map map[int]*DoubleListNode
    cap int
}


func Constructor(capacity int) LRUCache {
    return LRUCache{cap: capacity, List: &DoubleList{}, Map: make(map[int]*DoubleListNode)}
}


func (this *LRUCache) Get(key int) int {
    node, ok := this.Map[key]
    if !ok {
        return -1
    }else{
        this.List.Remove(node)
        this.List.AddHead(node)
        return node.Val
    }
}


func (this *LRUCache) Put(key int, value int)  {
    node, ok := this.Map[key]
    if ok {
        node.Val = value
        this.List.Remove(node)
        this.List.AddHead(node)
    }else{
        if this.List.Size() == this.cap {
            removed := this.List.RemoveTail()
            delete(this.Map, removed.Key)
        }
        newNode := &DoubleListNode{Key:key, Val: value}
        this.List.AddHead(newNode)
        this.Map[key] = newNode
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
func main() {
    cache := Constructor(105)

    fi, err := os.Open("test.txt")
    if err != nil {
        fmt.Printf("Error: %s\n", err)
        return
    }
    defer fi.Close()

    br := bufio.NewReader(fi)
    for {
        a, _, c := br.ReadLine()
        if c == io.EOF {
            break
        }
        str := string(a)
        if !strings.Contains(str, "//") {
            if strings.Contains(str, ",") {
                arr := strings.Split(str, ",")
                key, err1 := strconv.Atoi(arr[0])
                value, err2 := strconv.Atoi(arr[1])
                if err1 != nil || err2 != nil {
                    fmt.Println("error")
                    return
                }
                cache.Put(key, value)
            }else{
                key, _ := strconv.Atoi(str)
                cache.Get(key)
            }
        }
    }
    cache.List.PrintAll()
}