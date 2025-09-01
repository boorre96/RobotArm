# Variables
BUILD_DIR = build
DEBUG = debug


# Targets builds
build/debug:
	mkdir -p $(BUILD_DIR)/$(DEBUG)
	cmake -S . -B $(BUILD_DIR)/$(DEBUG)
	make -C $(BUILD_DIR)/$(DEBUG)

# Clean target
clean:
	rm -rf $(BUILD_DIR)

# Run Targets
run/debug: build/debug
	./$(BUILD_DIR)/$(DEBUG)/RobotArm