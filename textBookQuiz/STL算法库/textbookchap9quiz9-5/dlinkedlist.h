#pragma once
/*在双向链表中使用的节点类与单链表相比有何区别，试声明并实现双向链表中的节点类DNode*/

/*回答：双向链表中节点类同时有上一个节点和下一个节点的指针，而单链表的节点类只有下一个节点的指针*/

#include <iostream>
using namespace std;

template<class T>
class DNobe {
private:
	DNobe<T>* prv;
	DNobe<T>* next;

public:
	T data;

	DNobe(T d, DNobe<T>* p = 0, DNobe<T>* n = 0) : data(d), prv(p), next(n) {}

	// 在当前节点之前插入节点 p，并维护链接
	void insertBefore(DNobe<T>* p) {
		p->prv = prv;
		p->next = this;
		if (prv) prv->next = p;
		prv = p;
	}

	// 在当前节点之后插入节点 p，并维护链接
	void insertAfter(DNobe<T>* p) {
		p->next = next;
		p->prv = this;
		if (next) next->prv = p;
		next = p;
	}

	// 删除当前节点之前的节点并返回被删除节点指针（不释放）
	DNobe<T>* deleteBefore() {
		if (prv == 0) return 0;
		DNobe<T>* removed = prv;
		prv = removed->prv;
		if (prv) prv->next = this;
		removed->prv = removed->next = 0;
		return removed;
	}

	// 删除当前节点之后的节点并返回被删除节点指针（不释放）
	DNobe<T>* deleteAfter() {
		if (next == 0) return 0;
		DNobe<T>* removed = next;
		next = removed->next;
		if (next) next->prv = this;
		removed->prv = removed->next = 0;
		return removed;
	}

	DNobe<T>* prvnode() { return prv; }
	DNobe<T>* nextnode() { return next; }
};

// 精简版双向链表，只包含用户需要的基础操作
template<class T>
class DLinkedList {
private:
	DNobe<T>* head;
	DNobe<T>* tail;
	DNobe<T>* curr;    // 当前节点指针
	int size;
	int position;      // 当前节点的位置：0..size-1，-1 表示无当前节点

	DNobe<T>* newNode(T d, DNobe<T>* p = 0, DNobe<T>* n = 0) {
		return new DNobe<T>(d, p, n);
	}
	void freeNode(DNobe<T>* p) { delete p; }

public:
	DLinkedList() : head(0), tail(0), curr(0), size(0), position(-1) {}
	~DLinkedList() { clear(); }

	// 在表头插入
	void insertFirst(T d) {
		DNobe<T>* n = newNode(d);
		if (size == 0) {
			head = tail = curr = n;
			position = 0;
		}
		else {
			head->insertBefore(n);
			head = n;
			// 插入表头会使当前索引右移
			if (position >= 0) position++;
		}
		size++;
	}

	// 在表尾插入
	void insertLast(T d) {
		DNobe<T>* n = newNode(d);
		if (size == 0) {
			head = tail = curr = n;
			position = 0;
		}
		else {
			tail->insertAfter(n);
			tail = n;
		}
		size++;
	}

	// 删除表头
	bool deleteFirst() {
		if (size == 0) return false;
		if (size == 1) {
			freeNode(head);
			head = tail = curr = 0;
			size = 0;
			position = -1;
			return true;
		}
		// 使用第二个节点删除其前驱（即原 head）
		DNobe<T>* second = head->nextnode();
		DNobe<T>* removed = second->deleteBefore();
		if (removed) freeNode(removed);
		head = second;
		// 更新当前位置与指针
		if (position == 0) {
			curr = head;
			// position 保持 0
		}
		else if (position > 0) {
			position--;
		}
		size--;
		return true;
	}

	// 删除表尾
	bool deleteLast() {
		if (size == 0) return false;
		if (size == 1) {
			freeNode(tail);
			head = tail = curr = 0;
			size = 0;
			position = -1;
			return true;
		}
		DNobe<T>* before = tail->prvnode();
		DNobe<T>* removed = before->deleteAfter();
		if (removed) freeNode(removed);
		tail = before;
		// 如果当前刚好在最后，移动到新尾
		if (position == size - 1) {
			curr = tail;
			position = size - 2;
		}
		size--;
		return true;
	}

	// 返回链表元素个数
	int getSize() const { return size; }

	// 返回当前位置（-1 表示无当前）
	int getPosition() const { return position; }

	// 在当前节点之前插入（无当前则插入表尾）
	bool insertBeforeCurrent(T d) {
		if (position < 0 || curr == 0) {
			insertLast(d);
			return true;
		}
		DNobe<T>* n = newNode(d);
		curr->insertBefore(n);
		if (curr == head) head = n;
		size++;
		position++; // 新节点插入在 curr 之前，会使 curr 的索引+1
		return true;
	}

	// 在当前节点之后插入（无当前则插入表尾）
	bool insertAfterCurrent(T d) {
		if (position < 0 || curr == 0) {
			insertLast(d);
			return true;
		}
		DNobe<T>* n = newNode(d);
		curr->insertAfter(n);
		if (curr == tail) tail = n;
		size++;
		return true;
	}

	// 删除当前节点之前的节点
	bool deleteBeforeCurrent() {
		if (position <= 0 || curr == 0) return false;
		DNobe<T>* removed = curr->deleteBefore();
		if (removed) freeNode(removed);
		position--;
		return true;
	}

	// 删除当前节点之后的节点
	bool deleteAfterCurrent() {
		if (position < 0 || curr == 0 || curr->nextnode() == 0) return false;
		DNobe<T>* removed = curr->deleteAfter();
		if (removed) {
			if (removed == tail) tail = curr;
			freeNode(removed);
			size--;
			return true;
		}
		return false;
	}

	// 移动游标到开头/结尾/上一项/下一项/指定位置
	void moveToStart() {
		if (size == 0) { curr = 0; position = -1; return; }
		curr = head; position = 0;
	}
	void moveToEnd() {
		if (size == 0) { curr = 0; position = -1; return; }
		curr = tail; position = size - 1;
	}
	void prev() {
		if (curr && curr->prvnode()) {
			curr = curr->prvnode();
			position--;
		}
	}
	void next() {
		if (curr && curr->nextnode()) {
			curr = curr->nextnode();
			position++;
		}
	}
	bool moveToPos(int pos) {
		if (pos < 0 || pos >= size) return false;
		DNobe<T>* p = head;
		for (int i = 0; i < pos; ++i) p = p->nextnode();
		curr = p;
		position = pos;
		return true;
	}

	// 获取当前节点的数据
	bool getCurrentData(T& d) const {
		if (curr == 0 || position < 0) return false;
		d = curr->data;
		return true;
	}

	// 清空链表
	void clear() {
		while (size > 0) deleteFirst();
	}

private:
	// internal deleteFirst used by clear()
	bool isdeleteFirst() {
		if (size == 0) return false;
		if (size == 1) {
			freeNode(head);
			head = tail = curr = 0;
			size = 0; position = -1;
			return true;
		}
		DNobe<T>* second = head->nextnode();
		DNobe<T>* removed = second->deleteBefore();
		if (removed) freeNode(removed);
		head = second;
		if (position == 0) curr = head;
		else if (position > 0) position--;
		size--;
		return true;
	}
};
