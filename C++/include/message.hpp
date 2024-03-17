#pragma once

class Message
{
private:
  int _id;
  int _value;

public:
  Message(int id, int value) : _id(id), _value(value) {}

  int getId() const { return _id; }
  int getValue() const { return _value; }
};
