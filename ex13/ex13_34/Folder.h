#ifndef FOLDER_H
#define FOLDER_H
#include <set>
class Message;
class Folder {
public:
	void addMsg(Message *);
	void remMsg(Message *);
private:
	std::set<Message*> messages;
};
#endif