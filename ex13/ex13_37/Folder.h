#ifndef FOLDER_H
#define FOLDER_H
#include <set>
class Message;
class Folder {
	friend class Message;
	friend void swap(Folder &, Folder &);
	friend void swap(Message &, Message &);
public:
	Folder() = default;
	Folder(const Folder &);
	Folder &operator=(const Folder &);
	~Folder();
	void save(Message &);
	void remove(Message &);
private:
	std::set<Message*> messages;
	void add_to_Messages(const Folder&);
	void remove_from_Messages();
	void addMsg(Message *);
	void remMsg(Message *);
};
void swap(Folder &, Folder &);
void swap(Message &, Message &);
#endif