uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// __attribute__((packed)) is used to avoid padding in the structs and to make sure the size of the struct is the same as the size of the data being sent
typedef enum __attribute__((packed))
{
  MESSAGE_TYPE_A = (uint8_t)0x00,
  MESSAGE_TYPE_B,
} MessageType;

typedef struct
{
  MessageType msg_type = (MessageType)MESSAGE_TYPE_A;
  char a[32];
  int b;
} MessageA;

typedef struct
{
  MessageType msg_type = (MessageType)MESSAGE_TYPE_B;
  float c;
  bool d;
} MessageB;