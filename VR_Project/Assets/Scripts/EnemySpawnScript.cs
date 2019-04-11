using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemySpawnScript : MonoBehaviour
{
    public GameObject[] enemies;

    float spawnCoeff = 2f;
    float nextSpawn = 0f;

    int spawnableObj;


    // Update is called once per frame
    void Update() {
        if (Time.time > nextSpawn) {
            spawnableObj = Random.Range(0, enemies.Length);
            print(spawnableObj);

            switch (spawnableObj) {
                case 1:
                    Instantiate(enemies[0], transform.position, Quaternion.identity);
                    break;
                case 2:
                    Instantiate(enemies[1], transform.position, Quaternion.identity);
                    break;
                case 3:
                    Instantiate(enemies[2], transform.position, Quaternion.identity);
                    break;
                case 4:
                    Instantiate(enemies[3], transform.position, Quaternion.identity);
                    break;
                case 5:
                    Instantiate(enemies[4], transform.position, Quaternion.identity);
                    break;
                case 6:
                    Instantiate(enemies[5], transform.position, Quaternion.identity);
                    break;
                case 7:
                    Instantiate(enemies[6], transform.position, Quaternion.identity);
                    break;
                case 8:
                    Instantiate(enemies[7], transform.position, Quaternion.identity);
                    break;
                case 9:
                    Instantiate(enemies[8], transform.position, Quaternion.identity);
                    break;
            }

            nextSpawn = Time.time + spawnCoeff;
        }
    }
}
