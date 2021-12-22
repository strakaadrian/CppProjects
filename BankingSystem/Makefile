CXX	:= g++

BUILD := build
TARGET := app

MODULES := Account App Transaction Date .
SRC_DIR := $(addprefix src/,$(MODULES))
BUILD_DIR := $(addprefix $(BUILD)/,$(MODULES))

SRC := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
OBJ := $(patsubst src/%.cpp,$(BUILD)/%.o,$(SRC))

all: $(BUILD_DIR) $(BUILD)/$(TARGET)

vpath %.cpp $(SRC_DIR)

define create-objs
$1/%.o: %.cpp
	$(CXX) -c $$< -o $$@
endef

$(foreach bdir,$(BUILD_DIR),$(eval $(call create-objs,$(bdir))))

$(BUILD)/$(TARGET): $(OBJ)
	$(CXX) $^ -o $@

$(BUILD_DIR):
	@mkdir -p $@

.PHONY: clean

clean:
	@rm -rf $(BUILD)
