/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_classes.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:52:42 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/29 13:34:53 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

class YoutubeChannel
{
public:
  std::string Name;
  std::string OwnerName;
  int SubscribersCount;
  std::list<std::string> PublishedVideoTitles;

  YoutubeChannel(std::string name, std::string ownerName)
  {
    Name = name;
    ownerName = ownerName;
    SubscribersCount = 0;
        
  }
  void GetInfo(){
      std::cout << "Name: " << Name << std::endl;
      std::cout << "OwnerName: " << OwnerName << std::endl;
      std::cout << "SubscribersCount: " << SubscribersCount << std::endl;
      std::cout << "Videos: " << std::endl;
      for (std::string videoTitle : PublishedVideoTitles)
      {
        std::cout << videoTitle << std::endl;
      }
  }
};

int main()
{
  YoutubeChannel ytChannel("KarlfürsGrobe", "Jakob");
  ytChannel.PublishedVideoTitles.push_back("Video_1");
  ytChannel.PublishedVideoTitles.push_back("Video_2");
  ytChannel.PublishedVideoTitles.push_back("Video_3");
  YoutubeChannel ytChannel2("AmySings", "Amy");
  
  ytChannel.GetInfo();
  ytChannel2.GetInfo();
  return (0);
}