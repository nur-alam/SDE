var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
import { Module } from '@nestjs/common';
import { GamesService } from './games.service.js';
import { GamesController } from './games.controller.js';
let GamesModule = class GamesModule {
};
GamesModule = __decorate([
    Module({
        controllers: [GamesController],
        providers: [GamesService],
    })
], GamesModule);
export { GamesModule };
//# sourceMappingURL=games.module.js.map