import { GamesService } from './games.service.js';
import { CreateGameDto } from './dto/create-game.dto.js';
import { UpdateGameDto } from './dto/update-game.dto.js';
export declare class GamesController {
    private readonly gamesService;
    constructor(gamesService: GamesService);
    create(createGameDto: CreateGameDto): string;
    findAll(): string;
    findOne(id: string): string;
    update(id: string, updateGameDto: UpdateGameDto): string;
    remove(id: string): string;
}
