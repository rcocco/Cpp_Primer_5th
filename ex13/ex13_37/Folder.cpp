#include "Folder.h"
#include "Message.h"
void Folder::save(Message &m) {
	messages.insert(&m);
	m.addFldr(this);
}
void Folder::remove(Message &m) {
	messages.erase(&m);
	m.remFldr(this);
}
void Folder::addMsg(Message *m) {
	messages.insert(m);
}
void Folder::remMsg(Message *m) {
	messages.erase(m);
}
void Folder::add_to_Messages(const Folder &f) {
	for (auto m : f.messages) {
		m->addFldr(this);
	}
}
Folder::Folder(const Folder &f):messages(f.messages) {
	add_to_Messages(f);
}
void Folder::remove_from_Messages() {
	for (auto m : messages) {
		m->remFldr(this);
	}
}
Folder::~Folder() {
	remove_from_Messages();
}
Folder &Folder::operator=(const Folder &rhs) {
	remove_from_Messages();
	messages = rhs.messages;
	add_to_Messages(rhs);
	return *this;
}
void swap(Folder &lhs, Folder &rhs) {
	using std::swap;
	for (auto m : lhs.messages) {
		m->remFldr(&lhs);
	}
	for (auto m : rhs.messages) {
		m->remFldr(&rhs);
	}
	swap(lhs.messages, rhs.messages);
	for (auto f : lhs.messages) {
		f->addFldr(&lhs);
	}
	for (auto f : rhs.messages) {
		f->addFldr(&rhs);
	}
}