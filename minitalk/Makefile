CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
SERVER_DEFS = -D_POSIX_C_SOURCE=200809L

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include

CLIENT  = $(BIN_DIR)/client
SERVER  = $(BIN_DIR)/server

CLIENT_BONUS = $(BIN_DIR)/client_bonus
SERVER_BONUS = $(BIN_DIR)/server_bonus

SRCS_CLIENT   = $(SRC_DIR)/client.c
SRCS_SERVER   = $(SRC_DIR)/server.c
SRCS_COMMON   = $(SRC_DIR)/utils.c

SRCS_CLIENT_BONUS = $(SRC_DIR)/client_bonus.c
SRCS_SERVER_BONUS = $(SRC_DIR)/server_bonus.c

OBJS_CLIENT   = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_CLIENT) $(SRCS_COMMON))
OBJS_SERVER   = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_SERVER) $(SRCS_COMMON))

OBJS_CLIENT_BONUS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_CLIENT_BONUS) $(SRCS_COMMON))
OBJS_SERVER_BONUS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_SERVER_BONUS) $(SRCS_COMMON))

.PHONY: all clean fclean re bonus

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJS_CLIENT) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): $(OBJS_SERVER) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER_BONUS): $(OBJS_SERVER_BONUS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/server.o:        CFLAGS += $(SERVER_DEFS)
$(OBJ_DIR)/server_bonus.o:  CFLAGS += $(SERVER_DEFS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all
