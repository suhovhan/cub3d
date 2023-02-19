// #include  "cub3d.h"

// int flat(t_data *data)
// {
//   t_raycaster raycast;
//   int x = -1;

//   raycast.pos_x = (data->pos_x * SIZE) + (SIZE / 2);
//   raycast.pos_y = (data->pos_y * SIZE) + (SIZE / 2);
//   raycast.dir_x = 1;
//   raycast.dir_y = 0;
//   raycast.plane_x = 0;
//   raycast.plane_y = 0.66;
//   raycast.time = 0;
//   raycast.oldtime = 0;
//   while (++x < WIN_WIDTH)
//   {
//     raycast.camera_x = 2 * x / (double)WIN_WIDTH - 1;
//     raycast.ray_dir_x = raycast.dir_x + raycast.plane_x * raycast.camera_x;
//     raycast.ray_dir_y = raycast.dir_y + raycast.plane_y * raycast.camera_x;
//     raycast.map_x = (int)raycast.pos_x;
//     raycast.map_y = (int)raycast.pos_y;
//     raycast.side_dist_x;
//     raycast.side_dist_y;
//     raycast.delta_dist_x;
//     raycast.delta_dist_y;
//     if (raycast.ray_dir_x == 0)
//       raycast.delta_dist_x = 1e30;
//     else
//      raycast.delta_dist_x = fabs(1 / raycast.ray_dir_x);
//     if (raycast.ray_dir_y == 0)
//       raycast.delta_dist_y = 1e30;
//     else
//      raycast.delta_dist_y = fabs(1 / raycast.ray_dir_y);

//     double perpWallDist;
//     int hit = 0;
//     int side;
//     if(raycast.ray_dir_x < 0)
//     {
//       raycast.step_x = -1;
//       raycast.side_dist_x = (raycast.pos_x - raycast.map_x) * raycast.delta_dist_x;
//     }
//     else
//     {
//       raycast.step_x = 1;
//       raycast.side_dist_x = (raycast.map_x + 1.0 - raycast.pos_x) * raycast.delta_dist_x;
//     }
//     if(raycast.ray_dir_y < 0)
//     {
//       raycast.step_y = -1;
//       raycast.side_dist_y = (raycast.ray_pos_y - raycast.map_y) * raycast.delta_dist_y;
//     }
//     else
//     {
//       raycast.step_y = 1;
//       raycast.side_dist_y = (raycast.map_y + 1.0 - raycast.pos_y) * raycast.delta_dist_y;
//     }
//     while(hit == 0)
//     {
//       if(raycast.side_dist_x < raycast.side_dist_y)
//       {
//         raycast.side_dist_x += raycast.delta_dist_x;
//         raycast.map_x += raycast.step_x;
//         side = 0;
//       }
//       else
//       {
//         raycast.side_dist_y += raycast.delta_dist_y;
//         raycast.map_y += raycast.step_y;
//         side = 1;
//       }
//       if(data->map[raycast.map_x][raycast.map_y] > 0) hit = 1;
//     }
//     if(side == 0) perpWallDist = (raycast.side_dist_x - raycast.delta_dist_x);
//     else          perpWallDist = (raycast.side_dist_y - raycast.delta_dist_y);
//     int lineHeight = (int)(WIN_HEIGHT / perpWallDist);
//     int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
//     if(drawStart < 0) drawStart = 0;
//     int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
//     if(drawEnd >= WIN_HEIGHT) drawEnd = WIN_HEIGHT - 1;
//     verLine(x, drawStart, drawEnd, color);
//   }
//   raycast.old_time = time;
//   raycast.time = getTicks();
//   double frameTime = (raycast.time - raycast.old_time) / 1000.0;
//   print(1.0 / frameTime);
//   redraw();
//   cls();

//   double moveSpeed = frameTime * 5.0;
//   double rotSpeed = frameTime * 3.0;
//   // readKeys();
//   // if(keyDown(SDLK_UP))
//   // {
//   //   if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
//   //   if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
//   // }
//   // if(keyDown(SDLK_DOWN))
//   // {
//   //   if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
//   //   if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
//   // }
//   // if(keyDown(SDLK_RIGHT))
//   // {
//   //   double oldDirX = dirX;
//   //   dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
//   //   dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
//   //   double oldPlaneX = planeX;
//   //   planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
//   //   planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
//   // }
//   // if(keyDown(SDLK_LEFT))
//   // {
//   //   double oldDirX = dirX;
//   //   dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
//   //   dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
//   //   double oldPlaneX = planeX;
//   //   planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
//   //   planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
//   // }
//   return (0);
// }
