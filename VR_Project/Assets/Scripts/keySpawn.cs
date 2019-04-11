using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class keySpawn : MonoBehaviour
{

    public GameObject keyObject;
    public Transform [] spawnkeyPoints;
    
     void Start()
    {
        Transform spawnPoint = spawnkeyPoints[Random.Range(0, spawnkeyPoints.Length)];
        Instantiate(keyObject, spawnPoint.position, spawnPoint.rotation);
    }

    //    //int spawnKey;
    //    public GameObject [] key;
    //    public Transform[] spawnKeyPoints;

    //    void randomSpawnKey(Transform key)
    //    {
    //        Transform spawnThekey = spawnKeyPoints[Random.Range(0, spawnKeyPoints.Length)];
    //        print(spawnKeyPoints);
    //    }


}
