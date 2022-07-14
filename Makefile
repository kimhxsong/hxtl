DOCKER_COMPOSE = docker-compose
DOCKER_COMPOSE_FILE = ./build/docker-compose.yml
DC = $(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE)

.PHONY: remove
usage:
	@echo "Usage: make <command> [c=<name>]"
	@echo "<command>: docker-compose command"
	@echo "<name>: service_name specified in docker-compose.yml"

.PHONY: run
run:
	@$(DC) run $(c)

.PHONY: up
up: build
	@$(DC) up -d $(c)

.PHONY: down
down:
	@$(DC) down $(c)

.PHONY: remove
start:
	@$(DC) start $(c)

.PHONY: stop
stop:
	@$(DC) stop $(c)

.PHONY: restart
restart:
	@$(DC) stop $(c)
	@$(DC) start $(c)

.PHONY: attach
attach:
	@$(DC) attach $(c)

.PHONY: stat
stat:
	@$(DC) stat $(c)

.PHONY: logs
logs:
	@$(DC) logs $(c)

.PHONY: inspect
inspect:
	@$(DC) inspect $(c)

.PHONY: remove
remove:
	@$(DC) remove $(c)

.PHONY: dclean
dclean:
	-@2>/dev/null docker kill $(shell docker ps -qa)
	-@2>/dev/null docker rm $(shell docker ps -qa)
	-@2>/dev/null docker rmi $(shell docker images -qa)
	-@2>/dev/null docker volume rm $(shell docker volume ls -q)
	-@2>/dev/null docker network rm $(shell docker network ls -q)
