using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class ScoreManager : MonoBehaviour
{

    private static int score;
    private static int score1;
    private static int totalScore;

    public Text txtScore;


    // Update is called once per frame
    void Update()
    {
        score = EnemyController.playerScore;
        score1 = PlayerController.currentScore;
        totalScore = score + score1;
        txtScore.text = totalScore.ToString();
        //Debug.Log(score);
    }
}
