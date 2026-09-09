var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
var __param = (this && this.__param) || function (paramIndex, decorator) {
    return function (target, key) { decorator(target, key, paramIndex); }
};
import { Controller, Get, Post, Body, Patch, Param, Delete } from '@nestjs/common';
import { GamesService } from './games.service.js';
import { CreateGameDto } from './dto/create-game.dto.js';
import { UpdateGameDto } from './dto/update-game.dto.js';
let GamesController = class GamesController {
    gamesService;
    constructor(gamesService) {
        this.gamesService = gamesService;
    }
    create(createGameDto) {
        return this.gamesService.create(createGameDto);
    }
    findAll() {
        return this.gamesService.findAll();
    }
    findOne(id) {
        return this.gamesService.findOne(+id);
    }
    update(id, updateGameDto) {
        return this.gamesService.update(+id, updateGameDto);
    }
    remove(id) {
        return this.gamesService.remove(+id);
    }
};
__decorate([
    Post(),
    __param(0, Body()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [CreateGameDto]),
    __metadata("design:returntype", void 0)
], GamesController.prototype, "create", null);
__decorate([
    Get(),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", []),
    __metadata("design:returntype", void 0)
], GamesController.prototype, "findAll", null);
__decorate([
    Get(':id'),
    __param(0, Param('id')),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String]),
    __metadata("design:returntype", void 0)
], GamesController.prototype, "findOne", null);
__decorate([
    Patch(':id'),
    __param(0, Param('id')),
    __param(1, Body()),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String, UpdateGameDto]),
    __metadata("design:returntype", void 0)
], GamesController.prototype, "update", null);
__decorate([
    Delete(':id'),
    __param(0, Param('id')),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", [String]),
    __metadata("design:returntype", void 0)
], GamesController.prototype, "remove", null);
GamesController = __decorate([
    Controller('games'),
    __metadata("design:paramtypes", [GamesService])
], GamesController);
export { GamesController };
//# sourceMappingURL=games.controller.js.map